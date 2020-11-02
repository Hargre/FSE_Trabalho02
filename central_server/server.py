import socket
import curses

from interface import refresh_menu
from dispatcher import process_command

HOST = ''
PORT = 10003

DISTRIBUTED_SERVER_PORT = 10103
DISTRIBUTED_SERVER_HOST = '192.168.0.52'

def send_message(message, need_anwser=False):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect(('192.168.0.52', 10103))
        sock.sendall(bytes([message]))
        if need_anwser:
            data = sock.recv(1024).decode("utf-8")
            return data


def run_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    addr = (HOST, PORT)
    server.bind(addr)
    server.listen()

    while True:
        handle_request(server)


def handle_request(server):
    conn, client_addr = server.accept()
    data = conn.recv(1024)
    while data:
        process_command(data.decode("utf-8"))
        data = conn.recv(1024)
