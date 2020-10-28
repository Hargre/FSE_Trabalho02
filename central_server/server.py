import socket

HOST = ''
PORT = 10003

def client():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect(('127.0.0.1', 10103))
        for i in range(5):
            sock.sendall(b'hi %d' % i)
            data = sock.recv(1024).decode("utf-8")
            print(data.split(','))



