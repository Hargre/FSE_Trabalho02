from server import send_message
import time


def get_state():
    while 1:
        send_message(20, True)
        time.sleep(1)