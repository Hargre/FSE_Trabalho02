from server import send_message
from interface import refresh_menu
from state import HouseState
import threading
import os
from control import get_state

def main():

    refresh_menu(None)
    state = HouseState()

    state_updates = threading.Thread(target=get_state, args=(state,), daemon=True)
    state_updates.start()

    option = int(input())

    while option != 0:
        send_message(option)
        option = int(input())
    

if __name__ == '__main__':
    main()