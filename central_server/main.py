from server import send_message
from control import get_state

import threading

print("1 - Alterar L01")
print("2 - Alterar L02")
print("3 - Alterar L03")
print("4 - Alterar L04")
print("0 - Sair")

state_updates = threading.Thread(target=get_state)
state_updates.start()

option = int(input())

while option != 0:
    send_message(option)
    option = int(input())