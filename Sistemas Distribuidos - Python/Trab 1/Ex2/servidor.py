from xmlrpc.server import SimpleXMLRPCServer
from socketserver import ThreadingMixIn # Permitir paralelismo entre clientes.

class ThreadedXMLRPCServer(ThreadingMixIn, SimpleXMLRPCServer):
    pass

def soma(a, b): #retorna a soma de dois números.
    return a + b
def subtrai(a, b): #retorna a diferença entre dois números.
    return a - b

def multiplica(a, b): #retorna o produto entre dois números.
    return a * b

def divide(a, b): #retorna o quociente da divisão, tratando o caso de divisão por zero.
    if b == 0:
        return "Erro: divisão por zero não é permitida."
    return a / b

server = ThreadedXMLRPCServer(("localhost", 8000)) #Diferente de SimpleXMLRPCServer que é preciso que cada cliente espere sua vez
print("Servidor RPC (com threads) ouvindo na porta 8000...")

server.register_function(soma, "soma")
server.register_function(subtrai, "subtrai")
server.register_function(multiplica, "multiplica")
server.register_function(divide, "divide")
server.serve_forever()


