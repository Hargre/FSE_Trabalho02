import socket
import curses

HOST = ''
PORT = 10003

def send_message(message, stdscr, need_anwser=False):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect(('192.168.0.52', 10103))
        sock.sendall(bytes([message]))
        if need_anwser:
            data = sock.recv(1024).decode("utf-8")
            stdscr.addstr(0,0,data)
            stdscr.noutrefresh()
            curses.doupdate()
            # print(data.split(','))
