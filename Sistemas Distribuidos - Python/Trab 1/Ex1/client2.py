#!/usr/bin/python

import socket
import threading

def receive_messages(sock):
    while True:
        try:
            data = sock.recv(1024)
            if not data:
                break
            print(" " + data.decode() + "\n>", end="")
        except:
            break

s = socket.socket()
host = socket.gethostname()
port = 12345

s.connect((host, port))
print("Conectado ao servidor.")

thread = threading.Thread(target=receive_messages, args=(s,))
thread.start()

while True:
    msg = input("> ")
    s.send(msg.encode())
    if msg.lower() == "exit":
        print("Saindo...")
        break

s.close()
