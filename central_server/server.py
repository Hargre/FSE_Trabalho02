import socket
import curses

from interface import refresh_menu
from dispatcher import process_command

HOST = ''
PORT = 10003

DISTRIBUTED_SERVER_PORT = 10103
DISTRIBUTED_SERVER_HOST = '192.168.0.52'


def run_server(state):
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    addr = (HOST, PORT)
    server.bind(addr)
    server.listen()

    while True:
        handle_request(server, state)


def handle_request(server, state):
    conn, client_addr = server.accept()
    data = conn.recv(1024)
    while data:
        process_command(data.decode("utf-8"), state)
        data = conn.recv(1024)
