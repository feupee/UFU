# Felipe Santos Silva - 12221BCC042
# Marcos Gabriel Moreira Fonseca - 12221BCC043

"""Treinador configurável. Seleção pelo MAE FINAL de validação; teste reservado."""
import os
os.environ.setdefault('CUBLAS_WORKSPACE_CONFIG', ':4096:8')
import argparse, csv, hashlib, json, math, random, time
from pathlib import Path
import numpy as np
import torch
from torch import nn
from preparar_dados import gravar, hash_arquivo
RAIZ = Path(__file__).resolve().parent
OPTS = ['sgd','nesterov','adam','adamw','muon']
AGENDAS = ['constante','cosseno','warmup_cosseno','degraus']

def fator(agenda, passo, total):
    t = (passo-1)/max(1,total-1)
    if agenda == 'constante': return 1.0
    if agenda == 'degraus': return 1.0 if t < .5 else (.1 if t < .75 else .01)
    if agenda == 'cosseno': return .5*(1+math.cos(math.pi*t))
    warm = max(1,round(total*.1))
    if passo <= warm: return passo/warm
    return .5*(1+math.cos(math.pi*(passo-warm)/max(1,total-warm)))

class JogoNet(nn.Module):
    def __init__(self, n):
        super().__init__()
        self.camada1 = nn.Linear(n,64); self.camada2 = nn.Linear(64,32); self.head = nn.Linear(32,1)
    def forward(self,x): return self.head(torch.relu(self.camada2(torch.relu(self.camada1(x)))))

def carregar(split, device):
    with np.load(RAIZ/f'dados/processados/{split}.npz',allow_pickle=False) as d:
        X = torch.from_numpy(d['X'].copy()).to(device); y = torch.from_numpy(d['y'].copy()).to(device)
    if not torch.isfinite(X).all() or not torch.isfinite(y).all(): raise ValueError('Dados não finitos')
    return X,y

def norma(itens):
    return math.sqrt(sum(float(x.detach().double().square().sum()) for x in itens))

def finitos(itens):
    return all(bool(torch.isfinite(x).all()) for x in itens)

@torch.no_grad()
def avaliar(model,X,y):
    model.eval(); pred = model(X)
    mse = float((pred-y).square().mean()); mae = float((pred-y).abs().mean())*100
    model.train()
    return mse,mae

def csv_salvar(p, linhas):
    if not linhas: return
    with Path(p).open('w',newline='',encoding='utf-8') as f:
        w = csv.DictWriter(f,fieldnames=list(linhas[0])); w.writeheader(); w.writerows(linhas)

def executar(config, saida):
    saida = Path(saida); logs = saida/'logs'; logs.mkdir(parents=True,exist_ok=True)
    device = torch.device(config['device'])
    if device.type == 'cuda' and not torch.cuda.is_available(): raise RuntimeError('CUDA indisponível. Use o Python da .venv com PyTorch CUDA ou --device cpu.')
    if config['otimizador'] == 'muon' and not hasattr(torch.optim,'Muon'): raise RuntimeError('É necessário PyTorch >=2.9 com torch.optim.Muon.')
    s = config['semente']; random.seed(s); np.random.seed(s); torch.manual_seed(s)
    if device.type == 'cuda': torch.cuda.manual_seed_all(s)
    torch.set_num_threads(4); torch.use_deterministic_algorithms(True)
    torch.backends.cudnn.benchmark=False; torch.backends.cudnn.deterministic=True
    torch.backends.cuda.matmul.allow_tf32=False; torch.backends.cudnn.allow_tf32=False
    X,y = carregar('treino',device); V,v = carregar('validacao',device)
    n = X.shape[1]; model = JogoNet(n).to(device)
    lr = config['lr']; wd = config['weight_decay']; opt = config['otimizador']
    if opt in ['sgd','nesterov']:
        opts=[torch.optim.SGD(model.parameters(),lr=lr,momentum=.9,nesterov=opt=='nesterov',weight_decay=wd,foreach=False)]
    elif opt in ['adam','adamw']:
        cls = torch.optim.Adam if opt=='adam' else torch.optim.AdamW
        opts=[cls(model.parameters(),lr=lr,weight_decay=wd,foreach=False,fused=False)]
    else:
        matrizes=[model.camada1.weight,model.camada2.weight]; ids={id(p) for p in matrizes}
        opts=[torch.optim.Muon(matrizes,lr=lr,weight_decay=wd,momentum=.95,nesterov=True,ns_steps=5,adjust_lr_fn='original'),torch.optim.AdamW([p for p in model.parameters() if id(p) not in ids],lr=config['lr_aux'],weight_decay=wd,foreach=False,fused=False)]
    bases=[o.param_groups[0]['lr'] for o in opts]
    ident=hashlib.sha256(json.dumps(config,sort_keys=True).encode()).hexdigest()[:16]
    pasta=logs/ident
    if (pasta/'resultado.json').exists(): return json.loads((pasta/'resultado.json').read_text(encoding='utf-8'))
    pasta.mkdir(exist_ok=True); gravar(pasta/'config.json',config)
    grupos={'global':list(model.parameters()),'primeira':list(model.camada1.parameters()),'meio':list(model.camada2.parameters()),'saida':list(model.head.parameters())}
    mapa={id(p):i for i,p in enumerate(model.parameters())}
    gerador=torch.Generator().manual_seed(s); ordem=torch.empty(0,dtype=torch.long); cursor=0
    sinais=[]; validacao=[]; motivo=''; divergencia=False; completo=0
    lote=config['lote']; passos=config['passos']; intervalo=config['log_cada']; val_cada=config['validar_cada']
    if lote > len(X): raise ValueError('Lote maior que treino')
    if device.type=='cuda': torch.cuda.synchronize()
    inicio=time.perf_counter()
    for passo in range(1,passos+1):
        if cursor+lote > len(ordem): ordem=torch.randperm(len(X),generator=gerador); cursor=0
        ix=ordem[cursor:cursor+lote].to(device); cursor+=lote
        multiplicador=fator(config['agenda'],passo,passos)
        for o,base in zip(opts,bases):
            for g in o.param_groups: g['lr']=base*multiplicador
        for o in opts: o.zero_grad(set_to_none=True)
        loss=(model(X[ix])-y[ix]).square().mean()
        if not torch.isfinite(loss): divergencia=True; motivo=f'perda não finita no passo {passo}'; break
        loss.backward()
        if not finitos(p.grad for p in model.parameters()): divergencia=True; motivo=f'gradiente não finito no passo {passo}'; break
        registrar=passo==1 or passo%intervalo==0 or passo==passos
        if registrar:
            antes=[p.detach().clone() for p in model.parameters()]
            linha={'passo':passo,'perda_treino':float(loss.detach()),'lr':bases[0]*multiplicador,'lr_aux':bases[1]*multiplicador if len(bases)>1 else bases[0]*multiplicador}
            for nome,ps in grupos.items():
                linha[f'grad_{nome}']=norma(p.grad for p in ps); linha[f'theta_{nome}']=norma(ps)
        if config['clip']>0: torch.nn.utils.clip_grad_norm_(model.parameters(),config['clip'],error_if_nonfinite=True)
        for o in opts: o.step()
        if not finitos(model.parameters()): divergencia=True; motivo=f'parâmetro não finito no passo {passo}'; break
        completo=passo
        if registrar:
            for nome,ps in grupos.items(): linha[f'rho_{nome}']=norma(p.detach()-antes[mapa[id(p)]] for p in ps)/max(linha[f'theta_{nome}'],1e-12)
            sinais.append(linha)
        if passo%val_cada==0 or passo==passos:
            mse,mae=avaliar(model,V,v)
            if not math.isfinite(mse+mae): divergencia=True; motivo=f'validação não finita no passo {passo}'; break
            validacao.append(dict(passo=passo,mse=mse,mae_pontos=mae))
    if device.type=='cuda': torch.cuda.synchronize()
    tempo=time.perf_counter()-inicio
    if not divergencia: mse,mae=avaliar(model,V,v)
    else: mse=mae=None
    csv_salvar(pasta/'sinais.csv',sinais); csv_salvar(pasta/'validacao.csv',validacao)
    if not divergencia: torch.save({k:p.detach().cpu() for k,p in model.state_dict().items()},pasta/'modelo.pt')
    resultado=dict(execucao=ident,**config,passos_concluidos=completo,mae_val=mae,mse_val=mse,divergiu=divergencia,motivo=motivo,tempo_segundos=tempo,parametros=sum(p.numel() for p in model.parameters()),caracteristicas=n,pasta_logs=f'logs/{ident}')
    gravar(pasta/'resultado.json',resultado)
    todos=[json.loads(p.read_text(encoding='utf-8')) for p in sorted(logs.glob('*/resultado.json'))]
    csv_salvar(saida/'experimentos.csv',todos)
    print(f"{config['etapa']} | {opt} {config['agenda']} lr={lr:g} s={s} | MAE={mae if mae is not None else motivo}",flush=True)
    return resultado

def configuracao(otimizador='adamw',lr=.001,agenda='constante',semente=42,passos=500,lote=64,device='cuda',lr_aux=.001,etapa='manual'):
    c=dict(otimizador=otimizador,lr=float(lr),agenda=agenda,semente=semente,passos=passos,lote=lote,device=device,lr_aux=float(lr_aux),etapa=etapa,weight_decay=.01,clip=1.0,log_cada=10,validar_cada=50)
    c['dados_sha256']=hash_arquivo(RAIZ/'dados/processados/config.json'); c['treinador_sha256']=hash_arquivo(__file__)
    c['torch']=torch.__version__; c['numpy']=np.__version__; c['cuda']=str(torch.version.cuda)
    c['hardware']=torch.cuda.get_device_name(0) if device=='cuda' and torch.cuda.is_available() else 'CPU'
    return c

if __name__=='__main__':
    p=argparse.ArgumentParser()
    p.add_argument('--otimizador',choices=OPTS,default='adamw'); p.add_argument('--lr',type=float,default=.001)
    p.add_argument('--agenda',choices=AGENDAS,default='constante'); p.add_argument('--semente',type=int,default=42)
    p.add_argument('--passos',type=int,default=500); p.add_argument('--lote',type=int,default=64)
    p.add_argument('--device',choices=['cpu','cuda'],default='cuda'); p.add_argument('--lr-aux',type=float,default=.001)
    p.add_argument('--saida',type=Path,default=RAIZ/'resultados/manual'); p.add_argument('--config',type=Path)
    a=p.parse_args()
    c=json.loads(a.config.read_text(encoding='utf-8')) if a.config else configuracao(a.otimizador,a.lr,a.agenda,a.semente,a.passos,a.lote,a.device,a.lr_aux)
    if c['treinador_sha256']!=hash_arquivo(__file__) or c['dados_sha256']!=hash_arquivo(RAIZ/'dados/processados/config.json'): raise SystemExit('Código ou dados diferentes da configuração.')
    if c['passos']<10 or c['lote']<1: raise SystemExit('Use passos >=10 e lote positivo.')
    executar(c,a.saida)
