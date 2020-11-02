from server import run_server
from control import send_message
from interface import refresh_menu
from state import HouseState
import threading
import os
from control import get_state

def main():

    state = HouseState()
    refresh_menu(state)

    state_updates = threading.Thread(target=get_state, args=(state,), daemon=True)
    server = threading.Thread(target=run_server, daemon=True)
    state_updates.start()
    server.start()

    option = int(input())

    while option != 0:
        if option == 7:
            refresh_menu(state)
        else:
            send_message(option)
        option = int(input())
    

if __name__ == '__main__':
    main()