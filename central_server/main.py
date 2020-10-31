from server import send_message
from interface import refresh_menu
import threading
import os

def main():

    refresh_menu(None)    

    state_updates = threading.Thread(target=get_state)
    state_updates.start()

    option = int(input())

    while option != 0:
        send_message(option)
        option = int(input())
    

if __name__ == '__main__':
    main()