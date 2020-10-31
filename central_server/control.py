from server import send_message
import time


def get_state(stdscr):
    while 1:
        send_message(20, True, stdscr)
        time.sleep(1)