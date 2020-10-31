from server import send_message
import time


def get_state(stdscr):
    global stop = 0
    while 1:
        send_message(20, stdscr, True)
        time.sleep(1)
        if stop:
            break