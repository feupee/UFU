"""Gera relatório com resultados medidos e código-fonte em apêndice."""
import argparse
import json
import statistics as st
import textwrap
from collections import defaultdict
from pathlib import Path
from xml.sax.saxutils import escape
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from reportlab.lib import colors
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.enums import TA_CENTER
from reportlab.lib.utils import ImageReader
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle, PageBreak, Image, Preformatted
from reportlab.lib.pagesizes import A4

ROOT = Path(__file__).parent


def generate(source, output, environment, authors):
    data = json.loads(source.read_text(encoding='utf-8'))
    groups = defaultdict(list)
    for row in data['results']:
        groups[row['k'],row['height'],row['width']].append(row)
    expected = {(1,100,100),(1,200,50),(1,500,20),(2,2000,100),(2,4000,50),(2,10000,20)}
    if set(groups) != expected or any(len(v)!=data['repeats'] for v in groups.values()):
        raise ValueError('Experimento incompleto ou configurações incompatíveis com este relatório.')
    output.parent.mkdir(parents=True,exist_ok=True)
    styles=getSampleStyleSheet()
    styles.add(ParagraphStyle(name='BodyPT',fontName='Helvetica',fontSize=10,leading=14,spaceAfter=8))
    styles.add(ParagraphStyle(name='SmallPT',fontName='Helvetica',fontSize=8,leading=10,spaceAfter=5))
    styles.add(ParagraphStyle(name='TitlePT',fontName='Helvetica-Bold',fontSize=27,leading=32,textColor=colors.HexColor('#12354b'),spaceAfter=18))
    styles.add(ParagraphStyle(name='CodePT',fontName='Courier',fontSize=6.5,leading=8))
    story=[]
    def p(text, style='BodyPT'): story.append(Paragraph(text,styles[style]))
    def title(text): p(text,'Heading1')
    def page(): story.append(PageBreak())
    def table(rows, widths=None):
        rendered=[[Paragraph(escape(str(c)),styles['SmallPT']) for c in row] for row in rows]
        t=Table(rendered,colWidths=widths,repeatRows=1,hAlign='LEFT')
        t.setStyle(TableStyle([('BACKGROUND',(0,0),(-1,0),colors.HexColor('#e4edf3')),('VALIGN',(0,0),(-1,-1),'TOP'),('LINEBELOW',(0,0),(-1,0),1,colors.HexColor('#12354b')),('ROWBACKGROUNDS',(0,1),(-1,-1),[colors.white,colors.HexColor('#f4f7fa')]),('LEFTPADDING',(0,0),(-1,-1),6),('RIGHTPADDING',(0,0),(-1,-1),6),('BOTTOMPADDING',(0,0),(-1,-1),7)]))
        story.append(t);story.append(Spacer(1,10))
    def mean(rows,key): return st.mean(r[key] for r in rows)
    def fmt(x): return f'{x:.3f}'
    p('SEGURANÇA DA INFORMAÇÃO','Heading2')
    p('Rainbow Tables<br/>com Diceware','TitlePT')
    p('Implementação em Python, validação e análise experimental','Heading2')
    p('Autores: '+escape(authors))
    p('Referência didática: Ivan Sendin, FACOM/UFU. Aula de 13 de outubro de 2026 [1].')
    p('Ambiente das medições: <b>'+escape(environment)+'</b>.')
    p('Este documento reúne implementação, testes e resultados. Os tempos e recursos descritos pertencem ao ambiente declarado, não necessariamente ao computador dos alunos. Os nomes dos autores devem ser preenchidos antes da entrega.')
    title('Resumo')
    p(f'Implementou-se uma Rainbow Table para senhas formadas por uma ou duas entradas da lista Diceware original, com SHA-256 e o prefixo fixo GBC083. Foram avaliadas seis configurações, com {data["repeats"]} repetições e {data["trials"]} consultas aleatórias por execução. A correção foi verificada em universos pequenos por busca exaustiva e nos experimentos por comparação com a cobertura exata das cadeias. As medições distinguem tempo de construção, armazenamento, alocações Python e tempo de consulta.')
    a=groups[1,500,20];b=groups[2,10000,20]
    p(f'Na configuração de 500 cadeias e 20 passos, a cobertura média para uma palavra foi {100*mean(a,"coverage"):.2f}%. Com duas palavras, 10.000 cadeias e 20 passos cobriram {100*mean(b,"coverage"):.4f}% do universo. O crescimento do espaço de senhas explica a grande diferença, mesmo com aumento do orçamento de construção.')
    p('Organização: modelo e algoritmo; metodologia; resultados; análise e reprodução; referências; código-fonte integral dos módulos de execução e testes.')
    page();title('1. Modelo e implementação')
    p('A lista contém D = 7.776 entradas [2]. Cada senha possui exatamente k palavras, com repetição permitida, ordem relevante e um espaço ASCII como separador. Não há conversão de caixa nem remoção de pontuação. Os códigos de cinco dados identificam as entradas e não compõem a senha.')
    table([['k','Espaço N = D^k','Orçamento m × t'],[1,'7.776','10.000 passos'],[2,'60.466.176','200.000 passos']],[60,200,230])
    p('O hash é H(s) = SHA256(b"GBC083" + UTF8(s)), conforme [1]. O retorno interno tem 32 bytes. O vetor H("1234") é verificado por teste automatizado. O prefixo público e fixo não equivale a um salt aleatório individual: a mesma RT continua reutilizável para todas as senhas submetidas a esse esquema.')
    p('A redução da coluna i é o inteiro big-endian de SHA256(b"RT-R1" + i em 8 bytes big-endian + h), módulo N. O resultado é um ID decodificado em k dígitos na base D, que selecionam as palavras. Assim, qualquer saída corresponde a uma senha válida. A segunda aplicação de SHA-256 mistura a cor com o hash; seu custo integra os tempos medidos. O módulo introduz um viés desprezível neste espaço frente a 2^256, sem promessa de ausência de colisões.')
    p('Cada cadeia tem t passos: x[j+1] = R[j](H(x[j])), de j = 0 até t-1. Somente (x[0], x[t]) é armazenado. Os inícios são amostrados sem reposição. Um dicionário Python associa cada final a uma lista de inícios, preservando cadeias com finais iguais. A lista Diceware e metadados acompanham a serialização JSON.')
    p('A consulta testa posições do hash de t-1 até 0. Em cada hipótese, aplica a cor da posição e segue até o fim. Quando o final existe, reconstrói todas as cadeias candidatas ainda não examinadas e compara os hashes. Somente uma igualdade de hash produz resposta. O último ID x[t] não conta na cobertura daquela cadeia, pois não foi hasheado nela.')
    p('Construção: O(m × t) passos; extremos: O(m), além da lista. A consulta de hipóteses pode exigir O(t²) passos, acrescidos de O(c × t) para c cadeias candidatas distintas. Cores reduzem fusões causadas por encontros em colunas diferentes; encontros na mesma coluna ainda compartilham o restante da cadeia.')
    page();title('2. Metodologia e ambiente')
    hw=data['hardware']
    table([['Item','Valor'],['CPU',hw['cpu']],['CPUs lógicas visíveis',hw['logical_cpus']],['RAM visível',f'{hw["visible_ram_bytes"]/2**30:.2f} GiB' if hw['visible_ram_bytes'] else 'Não identificada'],['Sistema',hw['platform']],['Python',hw['python']],['Execução',hw['execution']],['Limites cgroup',str(hw.get('cgroup',{}))]],[120,370])
    p('Quando cgroup é informado, cpu.max usa quota/período em microssegundos e memory.max usa bytes. Valores visíveis podem refletir o host; limites do contêiner são mais restritivos. Não foi utilizado paralelismo ou GPU. Tempos em ambiente compartilhado podem variar por carga externa.')
    p(f'Cada configuração usa sementes 100 até {99+data["repeats"]} para os inícios. Os alvos usam sementes 900000 + 1000k + repetição, com {data["trials"]} sorteios uniformes com reposição por execução. Dentro do mesmo k e repetição, as configurações recebem os mesmos alvos. A seleção de alvos é independente da seleção dos inícios. As repetições variam a tabela e a amostra.')
    p('Tempos são medidos com perf_counter. Construção exclui carregamento da lista e gravação em disco. Consulta exclui geração do hash alvo e leitura do arquivo: a tabela já está em memória. O tamanho em disco inclui JSON, lista e metadados. Uma reconstrução separada, com tracemalloc, mede o pico de alocações Python da construção; ele não representa RAM/RSS total e não inclui a lista carregada antes da medição.')
    p('A cobertura exata é auditada reconstruindo as cadeias e armazenando os IDs hasheados em um conjunto. Essa auditoria consome memória adicional, excluída das métricas da RT. Para cada alvo, exige-se equivalência entre pertencimento ao conjunto e sucesso da busca. Toda senha encontrada também é validada pelo hash.')
    p('Sete testes automatizados cobrem: vetor do professor, integridade da lista, codificação bijetiva, redução determinística e válida, busca exaustiva versus cobertura em espaços pequenos, finais duplicados e persistência, ausência e entradas inválidas. O arquivo testes.txt registra a execução inicial aprovada.')
    page();title('3. Resultados medidos')
    p('Valores abaixo são médias entre repetições. Sucesso é a média das taxas amostrais; cobertura é a fração exata de IDs distintos hasheados. KiB = 1.024 bytes. A coluna de memória mede alocações Python, não RAM total.')
    rows=[['k / m / t','Cobertura %','Sucesso %','Geração s','Busca ms','Disco KiB','Pico KiB']]
    for (k,m,t),rs in groups.items():
        rows.append([f'{k} / {m} / {t}',f'{100*mean(rs,"coverage"):.3f}',f'{100*mean(rs,"success_rate"):.2f}',fmt(mean(rs,'build_s')),fmt(mean(rs,'mean_lookup_ms')),f'{mean(rs,"disk_bytes")/1024:.1f}',f'{mean(rs,"python_peak_bytes")/1024:.1f}'])
    table(rows,[100,65,65,65,65,65,65])
    fig,axes=plt.subplots(1,2,figsize=(9,3.2))
    for ax,k in zip(axes,(1,2)):
        entries=[(key,rs) for key,rs in groups.items() if key[0]==k]
        ax.bar([f'{key[1]} × {key[2]}' for key,rs in entries],[mean(rs,'mean_lookup_ms') for key,rs in entries],color='#247c94')
        ax.set(title=f'{k} palavra(s)',ylabel='Tempo médio de busca (ms)',xlabel='Altura × largura')
        ax.spines[['top','right']].set_visible(False)
    fig.tight_layout();chart=output.parent/'tempos_busca.png';fig.savefig(chart,dpi=170);plt.close(fig)
    story.append(Image(str(chart),width=490,height=174))
    p('Figura 1. Tempo médio de consulta por configuração, incluindo sucessos e falhas. A escala é própria de cada painel. As configurações de uma e duas palavras têm orçamentos diferentes.','SmallPT')
    p('As configurações de cada k mantêm m × t constante. Mesmo assim, a cobertura varia porque os percursos repetem senhas e podem se fundir. O produto m × t não é uma contagem de senhas distintas.')
    page();title('4. Variabilidade e baixa taxa de sucesso')
    p('Cada linha apresenta uma execução. O IC95% de Wilson descreve a incerteza binomial da taxa de sucesso para aquela tabela fixa, sob sorteios uniformes independentes. Não é um intervalo para tempos nem um intervalo que resuma todas as tabelas possíveis.')
    rows=[['k / m / t','Semente','Acertos','IC95% sucesso','Busca média ms']]
    for r in data['results']:
        lo,hi=r['wilson95']
        rows.append([f'{r["k"]} / {r["height"]} / {r["width"]}',r['seed'],f'{r["successes"]}/{r["trials"]}',f'{100*lo:.2f}% a {100*hi:.2f}%',fmt(r['mean_lookup_ms'])])
    table(rows,[120,65,75,140,90])
    p('Com duas palavras, a cobertura fica próxima de 0,33%. Em 200 tentativas, isso representa aproximadamente 0,66 acerto esperado por tabela. Portanto, zero acertos é compatível com uma implementação correta e cobertura não nula. A auditoria exata evita interpretar uma amostra pequena como prova de ausência de cobertura.')
    page();title('5. Análise, limitações e reprodução')
    a=groups[1,100,100];b=groups[1,500,20]
    p(f'Para uma palavra, passar de 100 × 100 para 500 × 20 alterou o tempo médio de consulta de {mean(a,"mean_lookup_ms"):.3f} ms para {mean(b,"mean_lookup_ms"):.3f} ms e o arquivo de {mean(a,"disk_bytes")/1024:.1f} KiB para {mean(b,"disk_bytes")/1024:.1f} KiB. A diferença evidencia o compromisso entre extremos armazenados e recomputação. A lista incorporada ao JSON gera custo fixo, reduzindo a proporção aparente de crescimento do arquivo.')
    p('O orçamento de duas palavras é vinte vezes maior, mas seu universo é 7.776 vezes maior. A redução de sucesso decorre principalmente dessa relação. Os resultados não demonstram fraqueza criptográfica do SHA-256 nem se estendem a senhas longas Diceware. Explora-se um espaço de candidatos pequeno ou parcialmente coberto.')
    p('Não foi medido um baseline de força bruta ou dicionário completo: não se afirma superioridade sobre essas alternativas. Para apenas 7.776 entradas, um dicionário completo é simples e pode ser preferível. A RT demonstra a troca tempo-memória; sua pré-computação só pode ser amortizada quando reutilizada em consultas compatíveis.')
    p('Limitações: três formatos por espaço; uma família de reduções; poucos alvos para o cenário raro de duas palavras; tempos sujeitos ao ambiente; alocações Python não equivalem a RSS; tabela JSON sem otimização binária. Melhorias possíveis incluem mais repetições, mais consultas para taxas baixas, comparação com força bruta, tabelas binárias e estudo de diferentes famílias de redução. Não se garante cobertura integral.')
    p('Reprodução (na pasta do projeto, Python 3.10+):')
    story.append(Preformatted('python -m unittest -v\npython experimentos.py --output resultados_meu_pc\npython -m pip install -r requirements-relatorio.txt\npython relatorio.py --input resultados_meu_pc/resultados.json \\\n  --output relatorio_meu_pc.pdf --ambiente "Computador dos alunos" \\\n  --autores "Nome 1; Nome 2"',styles['CodePT']))
    title('Referências e integridade')
    p('[1] SENDIN, Ivan. Segurança da Informação: Aula Rainbow Tables. FACOM, Universidade Federal de Uberlândia, 13 out. 2026. Material fornecido pelo usuário, especialmente slides 46 e 47.','SmallPT')
    p('[2] REINHOLD, Arnold. Diceware word list. Link da aula: http://world.std.com/~reinhold/diceware.wordlist.asc. Cópia consultada em https://theworld.com/~reinhold/diceware.wordlist.asc, 21 out. 2026. Lista integral no pacote. A assinatura PGP não foi validada.','SmallPT')
    p('SHA-256 do arquivo Diceware utilizado:','SmallPT')
    story.append(Preformatted(data['list_sha256'],styles['CodePT']))
    p('Os módulos seguintes são transcritos do projeto que acompanha o relatório. O JSON inclui os resultados individuais das consultas. A geração de PDF é utilitária e não faz parte do algoritmo avaliado.','SmallPT')
    for filename in ['rt.py','test_rt.py','experimentos.py']:
        lines=[]
        for number,line in enumerate((ROOT/filename).read_text(encoding='utf-8').splitlines(),1):
            wrapped=textwrap.wrap(line,width=102,replace_whitespace=False,drop_whitespace=False) or ['']
            lines.append(f'{number:03}  '+wrapped[0])
            lines.extend('     '+x for x in wrapped[1:])
        for offset in range(0,len(lines),75):
            page();title(f'Apêndice - {filename}')
            p('Código-fonte; linhas longas quebradas apenas para exibição.','SmallPT')
            story.append(Preformatted('\n'.join(lines[offset:offset+75]),styles['CodePT']))
    def footer(canvas,doc):
        canvas.setStrokeColor(colors.HexColor('#bbcbd5'));canvas.line(45,39,550,39)
        canvas.setFont('Helvetica',8);canvas.setFillColor(colors.HexColor('#526570'))
        canvas.drawString(45,27,'Rainbow Tables com Diceware | Segurança da Informação')
        canvas.drawRightString(550,27,str(doc.page))
    SimpleDocTemplate(str(output),pagesize=A4,rightMargin=45,leftMargin=45,topMargin=42,bottomMargin=52,title='Rainbow Tables com Diceware',author=authors).build(story,onFirstPage=footer,onLaterPages=footer)
    print(output)


if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--input',type=Path,default=ROOT/'resultados'/'resultados.json')
    p.add_argument('--output',type=Path,default=ROOT/'relatorio_rainbow_table.pdf')
    p.add_argument('--ambiente',default='Ambiente remoto de execução do ChatGPT (contêiner Linux)')
    p.add_argument('--autores',default='A preencher pelos alunos')
    a=p.parse_args();generate(a.input,a.output,a.ambiente,a.autores)
