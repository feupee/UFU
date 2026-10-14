"""Quatro etapas, retomada por configuração, confirmação pareada e teste separado."""
import argparse,json,statistics
from pathlib import Path
import numpy as np
from treino import RAIZ, AGENDAS, executar, configuracao
from preparar_dados import gravar,hash_arquivo

def main():
    p=argparse.ArgumentParser()
    p.add_argument('--device',choices=['cuda','cpu'],default='cuda')
    p.add_argument('--passos',type=int,default=500); p.add_argument('--lote',type=int,default=64)
    p.add_argument('--saida',type=Path,default=RAIZ/'resultados/oficial')
    a=p.parse_args()
    if a.passos<10 or a.lote<1: raise SystemExit('Use passos >=10 e lote positivo.')
    a.saida.mkdir(parents=True,exist_ok=True)
    manifesto=dict(passos=a.passos,lote=a.lote,device=a.device,treinador=hash_arquivo(RAIZ/'treino.py'),executor=hash_arquivo(__file__),dados=hash_arquivo(RAIZ/'dados/processados/config.json'))
    arq=a.saida/'protocolo.json'
    if arq.exists() and json.loads(arq.read_text(encoding='utf-8'))!=manifesto: raise SystemExit('Esta saída pertence a outro protocolo. Use --saida com outra pasta.')
    gravar(arq,manifesto)
    def rodar(opt,lr,agenda='warmup_cosseno',seed=42,aux=.001,etapa='busca'):
        return executar(configuracao(opt,lr,agenda,seed,a.passos,a.lote,a.device,aux,etapa),a.saida)
    def chave(r): return float('inf') if r['divergiu'] else r['mae_val']
    print('ETAPA 1: baseline com três sementes',flush=True)
    baseline=[rodar('adamw',.001,'constante',s,etapa='baseline') for s in [42,43,44]]
    if any(r['divergiu'] for r in baseline): raise RuntimeError('Baseline divergiu; examine os registros antes de prosseguir.')
    print('ETAPA 2: cinco taxas por otimizador; extensão automática das bordas',flush=True)
    melhores={}; aux=.001
    # AdamW primeiro: sua melhor taxa será a taxa auxiliar de Muon.
    for opt in ['adamw','sgd','nesterov','adam','muon']:
        grid=np.logspace(-3,-1,5) if opt=='muon' else (np.logspace(-4,0,5) if opt in ['sgd','nesterov'] else np.logspace(-5,-1,5))
        runs=[rodar(opt,float(lr),aux=aux) for lr in grid]
        for extensao in range(13):
            runs.sort(key=lambda r:r['lr']); melhor=min(runs,key=chave)
            if not melhor['divergiu'] and melhor not in [runs[0],runs[-1]]: break
            if extensao==12: raise RuntimeError(f'Não foi encontrado ótimo interior para {opt}; logs preservados. Inspecione a busca antes de continuar.')
            razao=10**.5 if opt=='muon' else 10
            if melhor['divergiu'] or melhor is runs[0]: nova=runs[0]['lr']/razao
            else: nova=runs[-1]['lr']*razao
            runs.append(rodar(opt,nova,aux=aux))
        melhores[opt]=melhor
        if opt=='adamw': aux=melhor['lr']
        gravar(a.saida/'melhores_taxas.json',melhores)
    print('ETAPA 3: quatro agendas para os dois melhores e Muon',flush=True)
    escolhidos=sorted(melhores,key=lambda o:chave(melhores[o]))[:2]
    if 'muon' not in escolhidos: escolhidos.append('muon')
    candidatos=[]
    for opt in escolhidos:
        for agenda in AGENDAS:
            candidatos.append(rodar(opt,melhores[opt]['lr'],agenda,aux=aux,etapa='agendas'))
    top=sorted([r for r in candidatos if not r['divergiu']],key=chave)[:3]
    if len(top)<3: raise RuntimeError('Menos de três receitas válidas.')
    print('ETAPA 4: três receitas, três sementes cada',flush=True)
    receitas=[]
    for c in top:
        runs=[rodar(c['otimizador'],c['lr'],c['agenda'],s,aux,'confirmacao') for s in [42,43,44]]
        ok=not any(r['divergiu'] for r in runs)
        notas=[r['mae_val'] for r in runs] if ok else []
        ganhos=[b['mae_val']-r['mae_val'] for b,r in zip(baseline,runs)] if ok else []
        receitas.append(dict(otimizador=c['otimizador'],lr=c['lr'],agenda=c['agenda'],execucoes=[r['execucao'] for r in runs],media=statistics.mean(notas) if ok else None,desvio=statistics.stdev(notas) if ok else None,ganho=statistics.mean(ganhos) if ok else None,desvio_ganho=statistics.stdev(ganhos) if ok else None,divergiu=not ok))
    boas=sorted([r for r in receitas if not r['divergiu']],key=lambda r:r['media'])
    if not boas: raise RuntimeError('Todas as receitas divergiram na confirmação.')
    melhor=boas[0]; ganho=melhor['ganho']; dispersao=melhor['desvio_ganho']
    # Heurística declarada para apenas três sementes, não teste de significância.
    supera=ganho>max(dispersao,melhor['desvio'],statistics.stdev(r['mae_val'] for r in baseline))
    # Também exige separação das outras receitas confirmadas para declarar vencedor único.
    unico=supera and all(r['media']-melhor['media']>max(r['desvio'],melhor['desvio']) for r in boas[1:])
    selecionada=melhor['execucoes'][0] if supera else baseline[0]['execucao']
    resumo=dict(baseline_execucoes=[r['execucao'] for r in baseline],baseline_media=statistics.mean(r['mae_val'] for r in baseline),baseline_desvio=statistics.stdev(r['mae_val'] for r in baseline),receitas=receitas,melhor_media=melhor,supera_baseline=supera,vencedor_unico=unico,selecionada_teste=selecionada,semente_teste=42,regra='Ganho > máximo dos desvios da baseline, candidata e ganhos pareados; vencedor único também separado das demais médias por seus desvios. Heurística, não significância estatística.')
    # Execução de diagnóstico com mesmo orçamento; não participa da seleção.
    rodar('sgd',10.0,'constante',etapa='diagnostico')
    gravar(a.saida/'resumo.json',resumo)
    from gerar_painel import gerar
    gerar(a.saida)
    print('Protocolo concluído. Painel e slide gerados. Teste ainda NÃO utilizado.')
    print('Saída:',a.saida.resolve())
if __name__=='__main__': main()
