from server import run_server
from control import send_message
from interface import refresh_menu
from interface import input_loop
from state import HouseState
import threading
import os
from control import get_state
from logger import Logger

def main():
    logger = Logger.get_instance()
    state = HouseState()

    state_updates = threading.Thread(target=get_state, args=(state,), daemon=True)
    server = threading.Thread(target=run_server, args=(state,), daemon=True)
    state_updates.start()
    server.start()
    refresh_menu(state)

    input_loop(state)


if __name__ == '__main__':
    main()