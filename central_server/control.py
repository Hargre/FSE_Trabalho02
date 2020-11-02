from server import send_message
from interface import refresh_menu
import time


def get_state(state):
    while 1:
        response = send_message(20, True)
        state.set_state(response)
        refresh_menu(state)
        time.sleep(1)

def regulate_temperature(state):
    if state.temperature < state.ref_temperature - 5 or state.temperature > state.ref_temperature + 5:
        send_message(10)
    else:
        send_message(11)


def trigger_alarm():
    print("ALARME!!!!!!!!")