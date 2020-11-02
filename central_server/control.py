from interface import refresh_menu
import time

def send_message(message, need_anwser=False):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect(('192.168.0.52', 10103))
        sock.sendall(bytes([message]))
        if need_anwser:
            data = sock.recv(1024).decode("utf-8")
            return data

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