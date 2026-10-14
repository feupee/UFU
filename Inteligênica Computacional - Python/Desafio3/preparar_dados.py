"""Divisão temporal fixa; todo ajuste de atributos usa exclusivamente treino."""
import argparse, collections, hashlib, json, math, re
from datetime import datetime, timezone
from pathlib import Path
import numpy as np
RAIZ = Path(__file__).resolve().parent
CAMPOS = ['genres', 'themes', 'platforms', 'game_modes', 'player_perspectives', 'involved_companies']

def hash_arquivo(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()

def gravar(p, obj):
    Path(p).write_text(json.dumps(obj, indent=2, ensure_ascii=False, allow_nan=False), encoding='utf-8')

def categorias(j, campo):
    itens = j.get(campo) or []
    if campo == 'involved_companies':
        itens = [i.get('company', {}) for i in itens]
    return sorted({str(i['id']) for i in itens if isinstance(i, dict) and 'id' in i})

def numericos(j):
    dt = datetime.fromtimestamp(j['first_release_date'], timezone.utc)
    return [dt.year, math.sin(2*math.pi*(dt.month-1)/12), math.cos(2*math.pi*(dt.month-1)/12)]

def preparar():
    p = argparse.ArgumentParser()
    p.add_argument('--arquivo', type=Path, default=RAIZ/'dados/jogos_igdb.json')
    p.add_argument('--min-votos', type=int, default=6)
    a = p.parse_args()
    destino = RAIZ/'dados/processados'
    if destino.exists():
        raise SystemExit('Dados já preparados. Preserve-os durante o protocolo; use uma nova pasta para outro experimento.')
    dados = json.loads(a.arquivo.read_text(encoding='utf-8'))
    removidos = collections.Counter(); jogos = []; ids = set()
    corte = datetime(2026,10,14,tzinfo=timezone.utc).timestamp()
    for j in dados:
        try:
            identificador = int(j['id']); nota = float(j['total_rating']); votos = float(j['total_rating_count'])
            data = float(j['first_release_date'])
            ano = datetime.fromtimestamp(data, timezone.utc).year
            valido = identificador > 0 and bool(str(j.get('name','')).strip()) and math.isfinite(nota) and 0 <= nota <= 100 and math.isfinite(votos) and votos >= a.min_votos and votos.is_integer() and 1950 <= ano and data < corte
        except (ValueError, TypeError, KeyError, OverflowError, OSError):
            valido = False
        if not valido:
            removidos['campos_invalidos_ou_fora_do_recorte'] += 1; continue
        if identificador in ids:
            removidos['id_duplicado'] += 1; continue
        ids.add(identificador)
        if not categorias(j,'genres') or not categorias(j,'platforms'):
            removidos['sem_genero_ou_plataforma'] += 1; continue
        j = dict(j); j['first_release_date'] = data
        j['_split'] = 'treino' if ano <= 2021 else ('validacao' if ano <= 2023 else 'teste')
        j['_nome'] = re.sub(r'\s+', ' ', str(j['name']).strip().casefold())
        jogos.append(j)
    # Evita nomes idênticos cruzando divisões. Não resolve todas as edições/remakes.
    pos = {'treino':0,'validacao':1,'teste':2}
    ultimo = {}
    for j in jogos: ultimo[j['_nome']] = max(ultimo.get(j['_nome'],0), pos[j['_split']])
    grupos = {s:[] for s in pos}
    for j in jogos:
        if pos[j['_split']] != ultimo[j['_nome']]: removidos['nome_repetido_em_divisao_posterior'] += 1
        else: grupos[j['_split']].append(j)
    for s in grupos:
        grupos[s].sort(key=lambda j:(j['first_release_date'],j['id']))
        if len(grupos[s]) < 100: raise ValueError(f'Divisão {s} insuficiente: {len(grupos[s])}')
    treino = grupos['treino']; vocab = {}; nomes = ['ano_z','mes_seno','mes_cosseno']
    for campo in CAMPOS:
        cont = collections.Counter(c for j in treino for c in categorias(j,campo))
        minimo = 10 if campo == 'involved_companies' else 1
        vocab[campo] = sorted(c for c,n in cont.items() if n >= minimo)
        nomes += [f'{campo}:{c}' for c in vocab[campo]] + [f'{campo}:ausente', f'{campo}:fora_vocabulario']
    numer = np.array([numericos(j) for j in treino], dtype=np.float64)
    media = float(numer[:,0].mean()); desvio = float(numer[:,0].std()) or 1.0
    destino.mkdir(parents=True)
    for split, itens in grupos.items():
        X = np.zeros((len(itens),len(nomes)),dtype=np.float32)
        X[:,:3] = np.array([numericos(j) for j in itens],dtype=np.float32)
        X[:,0] = (X[:,0]-media)/desvio
        offset = 3
        for campo in CAMPOS:
            mapa = {v:i for i,v in enumerate(vocab[campo])}; n = len(mapa)
            for k,j in enumerate(itens):
                valores = categorias(j,campo)
                if not valores: X[k,offset+n] = 1
                for v in valores: X[k,offset+mapa.get(v,n+1)] = 1
            offset += n+2
        y = np.array([j['total_rating']/100 for j in itens],dtype=np.float32).reshape(-1,1)
        assert np.isfinite(X).all() and np.isfinite(y).all()
        np.savez_compressed(destino/f'{split}.npz',X=X,y=y,ids=np.array([j['id'] for j in itens]),nomes=np.array([j['name'] for j in itens]))
    config = dict(alvo='total_rating',escala='0 a 100; y armazenado dividido por 100',min_votos=a.min_votos,original=len(dados),removidos=dict(removidos),quantidades={s:len(v) for s,v in grupos.items()},vocabulario=vocab,caracteristicas=nomes,ano_media=media,ano_desvio=desvio,fonte_sha256=hash_arquivo(a.arquivo),script_sha256=hash_arquivo(__file__),divisao='treino <=2021; validacao 2022-2023; teste >=2024, até 2026-10-13',limitacoes=['Snapshot atual: não comprova desempenho prospectivo em pré-vendas.', 'Sem version_parent na coleta original; nomes iguais não cobrem todas as edições.', 'Total_rating combina usuários e crítica; corte de seis votos pode gerar alvos ruidosos.', 'Empresas envolvidas não distinguem desenvolvedor de publicador nesta coleta.'])
    config['arquivos_sha256'] = {s:hash_arquivo(destino/f'{s}.npz') for s in grupos}
    gravar(destino/'config.json',config)
    print(json.dumps({k:config[k] for k in ['original','removidos','quantidades']},indent=2,ensure_ascii=False))
    print('Características:',len(nomes)); print('Nenhuma métrica calculada no teste.')
if __name__ == '__main__': preparar()
