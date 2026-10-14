# Felipe Santos Silva - 12221BCC042
# Marcos Gabriel Moreira Fonseca - 12221BCC043

"""Avaliação única da receita já congelada. Não ajusta o modelo usando o teste."""
import argparse,json
from pathlib import Path
import torch
from treino import RAIZ,JogoNet,carregar,avaliar
from preparar_dados import gravar,hash_arquivo

def main():
    p=argparse.ArgumentParser(); p.add_argument('--saida',type=Path,default=RAIZ/'resultados/oficial'); p.add_argument('--device',choices=['cpu','cuda'],default='cuda')
    a=p.parse_args(); destino=a.saida/'teste_final.json'
    if destino.exists(): raise SystemExit('Teste já avaliado nesta pasta. Consulte teste_final.json; não use o teste para novos ajustes.')
    resumo=json.loads((a.saida/'resumo.json').read_text(encoding='utf-8')); run=resumo['selecionada_teste']; pasta=a.saida/'logs'/run
    cfg=json.loads((pasta/'config.json').read_text(encoding='utf-8'))
    if cfg['treinador_sha256']!=hash_arquivo(RAIZ/'treino.py') or cfg['dados_sha256']!=hash_arquivo(RAIZ/'dados/processados/config.json'): raise RuntimeError('Código ou dados alterados desde a seleção.')
    X,y=carregar('teste',a.device); model=JogoNet(X.shape[1]).to(a.device)
    model.load_state_dict(torch.load(pasta/'modelo.pt',map_location=a.device,weights_only=True))
    mse,mae=avaliar(model,X,y)
    resultado=dict(execucao=run,semente=42,n_jogos=len(y),mae_pontos=mae,mse=mse,receita=cfg,regra='Receita selecionada na validação; semente 42 definida previamente.')
    gravar(destino,resultado); print(f'TESTE FINAL: MAE = {mae:.3f} pontos, {len(y)} jogos. Resultado salvo.')
if __name__=='__main__': main()
