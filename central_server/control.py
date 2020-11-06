import time
import socket
import subprocess
from logger import Logger
import threading

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
        regulate_temperature(state)
        time.sleep(1)

def regulate_temperature(state):
    if not state.temperature or not state.ref_temperature:
        return
    if state.temperature < state.ref_temperature - 5 or state.temperature > state.ref_temperature + 5:
        send_message(10)
    else:
        send_message(11)


def toggle_alarm(state):
    if not state.alarm_on and state.any_presence_openings_active():
        return False
    state.toggle_alarm()
    return True

def trigger_alarm(state):
    if state.alarm_on:
        alarm_playback = threading.Thread(target=play_alarm)
        alarm_playback.start()
        logger = Logger.get_instance()
        logger.log_alarm()


def play_alarm():
    alarm_playback = subprocess.Popen(['omxplayer', 'media/alarm.mp3'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, close_fds=True)
    time.sleep(5)
    alarm_playback.stdin.write(b'q')
