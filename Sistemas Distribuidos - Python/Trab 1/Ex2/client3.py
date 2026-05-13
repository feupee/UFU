import xmlrpc.client

proxy = xmlrpc.client.ServerProxy("http://localhost:8000/")

print("\n================= CALCULADORA RPC =================")
print("|  Codigo |          Operacao                      |")
print("|---------|----------------------------------------|")
print("|    1    |  Soma (a + b)                          |")
print("|    2    |  Subtracao (a - b)                     |")
print("|    3    |  Multiplicacao (a * b)                 |")
print("|    4    |  Divisao (a / b)                       |")
print("|    0    |  Sair                                  |")
print("====================================================")

while True:
    print("Qual operacao voce deseja realizar?\n")
    Resposta = input("> ")
    if Resposta == '0':
        print("Encerrando a calculadora. Ate mais!")
        break
    elif Resposta in ['1', '2', '3', '4']:
        a = float(input("Digite o primeiro numero (a): "))
        b = float(input("Digite o segundo numero (b): "))

        if Resposta == '1':
            resultado = proxy.soma(a, b)
            operacao = "soma"
        elif Resposta == '2':
            resultado = proxy.subtrai(a, b)
            operacao = "subtracao"
        elif Resposta == '3':
            resultado = proxy.multiplica(a, b)
            operacao = "multiplicacao"
        elif Resposta == '4':
            resultado = proxy.divide(a, b)
            operacao = "divisao"

        print(f"O resultado da {operacao} entre {a} e {b} é: {resultado}\n")