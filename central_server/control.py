from server import send_message
from interface import refresh_menu
import time


def get_state(state):
    while 1:
        response = send_message(20, True)
        state.set_state(response)
        refresh_menu(state)
        time.sleep(1)