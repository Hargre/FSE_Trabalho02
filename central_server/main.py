from server import send_message

import threading

print("1 - Alterar L01")
print("2 - Alterar L02")
print("3 - Alterar L03")
print("4 - Alterar L04")
print("0 - Sair")

option = int(input())

while option != 0:
    send_message(option)
    option = int(input())