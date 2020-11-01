import os

def refresh_menu(data):
    os.system('clear')
    print("1 - Alterar L01")
    print("2 - Alterar L02")
    print("3 - Alterar L03")
    print("4 - Alterar L04")
    print("0 - Sair")

    if data:
        print(data)