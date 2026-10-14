"""Relatórios derivados dos registros reais; não inventa convergência ou vencedor."""
import argparse,json,textwrap
from pathlib import Path
import numpy as np
import pandas as pd
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
from treino import RAIZ

def gerar(saida):
    saida=Path(saida)
    resumo=json.loads((saida/'resumo.json').read_text(encoding='utf-8'))
    runs=[json.loads(p.read_text(encoding='utf-8')) for p in (saida/'logs').glob('*/resultado.json')]
    porid={r['execucao']:r for r in runs}
    def sinal(r): return pd.read_csv(saida/r['pasta_logs']/'sinais.csv')
    def val(r): return pd.read_csv(saida/r['pasta_logs']/'validacao.csv')
    melhor=porid[resumo['melhor_media']['execucoes'][0]]
    baseline=porid[resumo['baseline_execucoes'][0]]
    muons=[r for r in runs if r['otimizador']=='muon' and not r['divergiu'] and r['semente']==42 and r['etapa'] in ['agendas','confirmacao']]
    muon=min(muons,key=lambda r:r['mae_val'])
    instavel=[r for r in runs if r['etapa']=='diagnostico'][0]
    cenarios=[(melhor,'Menor média confirmada (semente 42)'),(baseline,'Baseline (semente 42)'),(muon,'Melhor Muon em validação (semente 42)'),(instavel,'Diagnóstico: SGD, LR=10')]
    plt.rcParams.update({'font.size':9})
    with PdfPages(saida/'painel.pdf') as pdf:
        fig,axes=plt.subplots(4,1,figsize=(11.7,8.3),sharex=True)
        for cor,(r,label) in zip(['#1769aa','#db7c14','#408444','#c23161'],cenarios):
            path=saida/r['pasta_logs']/'sinais.csv'
            if not path.exists(): continue
            d=sinal(r)
            for ax,campo in zip(axes,['perda_treino','grad_global','theta_global','lr']): ax.plot(d.passo,d[campo],label=label,alpha=.8,color=cor)
            vp=saida/r['pasta_logs']/'validacao.csv'
            if vp.exists():
                dv=val(r); axes[0].plot(dv.passo,dv.mse,ls='--',alpha=.75,label=label+' / validação',color=cor)
        for ax,nome in zip(axes,['MSE (treino/validação)','Norma do gradiente','Norma dos parâmetros','Taxa aplicada']):
            ax.set_ylabel(nome); ax.set_yscale('symlog',linthresh=1e-5); ax.grid(alpha=.25)
        axes[0].legend(fontsize=6,ncol=2); axes[-1].set_xlabel('Passos')
        fig.suptitle('IGDB: sinais alinhados — sem cortar picos; tracejado = validação')
        fig.tight_layout(); pdf.savefig(fig); plt.close(fig)
        fig,ax=plt.subplots(figsize=(11.7,8.3))
        for opt in ['sgd','nesterov','adam','adamw','muon']:
            rs=sorted([r for r in runs if r['etapa']=='busca' and r['otimizador']==opt],key=lambda r:r['lr'])
            bons=[r for r in rs if not r['divergiu']]
            ax.plot([r['lr'] for r in bons],[r['mae_val'] for r in bons],'-o',label=opt)
            for r in rs:
                if r['divergiu']: ax.plot(r['lr'],.98,marker='x',color='red',transform=ax.get_xaxis_transform())
        ax.set_xscale('log'); ax.set_yscale('symlog',linthresh=1)
        ax.set(xlabel='Taxa de aprendizado máxima',ylabel='MAE final de validação (pontos na escala 0–100)',title='Busca de taxas — warmup + cosseno; cruz vermelha = execução não finita')
        ax.set_yticks([8,10,20,30,50],labels=['8','10','20','30','50']); ax.legend(); ax.grid(alpha=.3); fig.tight_layout(); pdf.savefig(fig); plt.close(fig)
        fig,axes=plt.subplots(3,1,figsize=(11.7,8.3),sharex=True)
        for r,label in [(baseline,'Baseline'),(muon,'Muon')]:
            d=sinal(r)
            for camada in ['global','primeira','meio','saida']:
                for ax,prefixo in zip(axes,['grad','theta','rho']): ax.plot(d.passo,d[f'{prefixo}_{camada}'],label=f'{label}: {camada}')
        for ax,nome in zip(axes,['Gradiente antes do clipping','Parâmetros antes do passo','Razão de atualização']):
            ax.set_ylabel(nome); ax.set_yscale('symlog',linthresh=1e-7); ax.grid(alpha=.3)
        axes[0].legend(ncol=4,fontsize=7); axes[-1].set_xlabel('Passos'); fig.suptitle('Comparação por camada e global'); fig.tight_layout(); pdf.savefig(fig); plt.close(fig)
    b=resumo['melhor_media']; d=sinal(melhor); dv=val(melhor)
    inicial=dv.iloc[0]; final=dv.iloc[-1]
    diagnostico=(f"Validação MSE: {inicial.mse:.4f} (passo {int(inicial.passo)}) → {final.mse:.4f} (passo {int(final.passo)}). "
                 f"Gradiente global máximo registrado: {d.grad_global.max():.3g}; "
                 f"razão de atualização global mediana: {d.rho_global.median():.3g}. "
                 f"A taxa aplicada terminou em {d.lr.iloc[-1]:.3g} e a razão global em {d.rho_global.iloc[-1]:.3g}: "
                 'a redução do passo no fim é compatível com refinamento, sem estabelecer causalidade.')
    status='Vencedor pela regra declarada' if resumo['vencedor_unico'] else ('Melhora sobre a baseline; empate entre candidatas' if resumo['supera_baseline'] else 'Sem ganho consistente sobre a baseline')
    fig=plt.figure(figsize=(13.33,7.5)); fig.patch.set_facecolor('#f7f9fc')
    fig.text(.055,.91,'Predição de notas de jogos • IGDB',fontsize=23,weight='bold',color='#153a59')
    fig.text(.055,.845,status,fontsize=16,color='#1f6470')
    linhas=[f"Menor média: {b['otimizador']} | {b['agenda']} | LR={b['lr']:g}",
            f"MAE: {b['media']:.2f} ± {b['desvio']:.2f} pontos | baseline: {resumo['baseline_media']:.2f} ± {resumo['baseline_desvio']:.2f}",
            f"Ganho pareado: {b['ganho']:.2f} ± {b['desvio_ganho']:.2f} pontos (três sementes; desvio amostral)",
            f"Protocolo: 5 otimizadores; ≥5 taxas; 4 agendas nos selecionados; {melhor['passos']} passos × lote {melhor['lote']}.",
            'Diagnóstico observado: '+diagnostico,
            'Limites: snapshot atual, poucas avaliações em parte da base e edições não totalmente identificadas. Não demonstra previsão prospectiva de pré-vendas.',
            'Teste reservado. Escolha pelo MAE final da validação; regra de variação é heurística, não teste estatístico.']
    yy=.75
    for texto in linhas:
        wrapped=textwrap.fill(texto,112)
        fig.text(.055,yy,wrapped,fontsize=12,va='top',linespacing=1.45)
        yy-=.035*(wrapped.count('\n')+1)+.025
    fig.savefig(saida/'slide.pdf',facecolor=fig.get_facecolor()); plt.close(fig)
    print('Gerados painel.pdf (3 páginas) e slide.pdf (1 página).')
if __name__=='__main__':
    p=argparse.ArgumentParser(); p.add_argument('--saida',type=Path,default=RAIZ/'resultados/oficial')
    gerar(p.parse_args().saida)
