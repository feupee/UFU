# Rainbow Table com Diceware — Segurança da Informação

Implementação didática em Python 3.10+; núcleo, testes e experimentos usam apenas a biblioteca padrão.

## Executar no Windows (PowerShell)

Abra um terminal na pasta extraída `rainbow_table`:

```powershell
py -m venv .venv
.\.venv\Scripts\python.exe -m unittest -v
.\.venv\Scripts\python.exe experimentos.py --trials 200 --repeats 3 --output resultados_meu_pc
```

Não é necessário ativar o ambiente virtual nem instalar pacotes para esses comandos.
No Linux/macOS substitua `py` por `python3` e o executável por `.venv/bin/python`.

Os experimentos podem levar alguns minutos, conforme o computador. O JSON é atualizado após cada execução; um arquivo interrompido contém resultados parciais, não uma bateria completa. O programa sobrescreve resultados na pasta de saída indicada. Use pastas diferentes para preservar medições anteriores.

## Gerar o PDF com os seus resultados

```powershell
.\.venv\Scripts\python.exe -m pip install -r requirements-relatorio.txt
.\.venv\Scripts\python.exe relatorio.py --input resultados_meu_pc/resultados.json --output relatorio_meu_pc.pdf --ambiente "Computador dos alunos" --autores "Nome 1; Nome 2"
```

O relatório recebido foi medido em ambiente remoto, identificado no documento. Não representa o seu PC. Preencha os nomes; revise o texto e confirme com o professor o número de palavras e o separador adotados. O relatório pode ser entregue como PDF único porque inclui o código de implementação, os experimentos e os testes em apêndice.

## Utilização avulsa

```powershell
.\.venv\Scripts\python.exe rt.py build --words 1 --height 500 --width 20 --output tabela.json
.\.venv\Scripts\python.exe rt.py hash "1234"
.\.venv\Scripts\python.exe rt.py lookup tabela.json HASH_HEXADECIMAL_DE_64_CARACTERES
```

Troque o marcador pelo hash desejado. `1234` demonstra o vetor do professor; não se garante que essa senha pertença ao espaço ou à cobertura da tabela. Uma busca sem sucesso não prova que a senha não está na lista.

## Decisões

- Lista integral original de Arnold Reinhold, 7776 entradas. Códigos de dados não fazem parte da senha.
- Uma ou duas palavras, separadas por um espaço ASCII, ordem relevante, repetição permitida, sem normalização.
- Hash `SHA256(b'GBC083' + senha.encode('utf-8'))`.
- Redução por coluna: `int(SHA256(b'RT-R1' + coluna_u64_be + hash)) % N`.
- IDs em base 7776 são decodificados em palavras, evitando armazenar todas as combinações.
- Todos os inícios com o mesmo final são preservados.
- Sementes determinísticas são usadas para reprodutibilidade; não para gerar senhas reais.
- Pico de alocações Python medido em reconstrução separada com tracemalloc; NÃO é pico de RAM/RSS total.
- Auditoria de cobertura usa memória adicional e não integra o custo normal da RT.

## Arquivos

`rt.py`: algoritmo e CLI; `test_rt.py`: testes; `experimentos.py`: medições;
`relatorio.py`: PDF e gráficos; `data/diceware.wordlist.asc`: lista original;
`resultados/resultados.json`: medições remotas completas; `resultados/testes.txt`: saída dos testes.

Fonte original indicada em aula: http://world.std.com/~reinhold/diceware.wordlist.asc
Cópia obtida em 21/10/2026: https://theworld.com/~reinhold/diceware.wordlist.asc
A lista conserva seu bloco de assinatura PGP; a assinatura não foi validada. O checksum SHA-256 do arquivo está no JSON para identificar a cópia utilizada.
