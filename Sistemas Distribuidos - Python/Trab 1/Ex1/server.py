#!/usr/bin/python

import socket
import threading

clients = []  # Lista de tuplas (socket, username)
client_counter = 1  # Contador para gerar nomes de usuários

def broadcast(msg, sender_socket):
    """Envia mensagem para todos os clientes, exceto o remetente"""
    for client_socket, _ in clients:
        if client_socket != sender_socket:
            try:
                client_socket.send(msg.encode())  # Codificar para bytes antes de enviar
            except:
                client_socket.close()
                clients.remove((client_socket, _))

def handle_client(c, addr):
    global client_counter

    username = f"client{client_counter}"
    client_counter += 1
    clients.append((c, username))
    print(f"{username} ({addr}) entrou no chat.")
    broadcast(f"{username} entrou no chat!", c)

    while True:
        try:
            data = c.recv(1024)  # Recebe a mensagem do cliente
            if not data:
                break

            decoded = data.decode().strip()  # Decodifica a mensagem

            if decoded.lower() == "exit":
                print(f"{username} saiu.")
                broadcast(f"{username} saiu do chat.", c)
                break

            print(f"{username} > {decoded}")
            # Envia a mensagem para todos os outros clientes
            broadcast(f"{username} > {decoded}", c)

        except:
            break

    c.close()
    clients.remove((c, username))
    print(f"Conexão encerrada com {addr}")

def start_server():
    s = socket.socket()
    host = socket.gethostname()  # Obtém o nome da máquina local
    port = 12345  # Porta que o servidor está ouvindo
    s.bind((host, port))
    s.listen(5)
    print(f"Servidor ouvindo em {host}:{port}")

    while True:
        c, addr = s.accept()
        thread = threading.Thread(target=handle_client, args=(c, addr))
        thread.start()

if __name__ == "__main__":
    start_server()
