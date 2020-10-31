from server import send_message
import time


stop = 0
def get_state(stdscr):
    while 1:
        send_message(20, stdscr, True)
        time.sleep(1)
        if stop:
            break