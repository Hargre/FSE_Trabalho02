import os

def refresh_menu(data):
    os.system('clear')
    print("--------- Servidor Central - Comandos ----------")
    print("|1 - Alterar Lâmpada 01\t 2 - Alterar Lâmpada 02")
    print("|3 - Alterar Lâmpada 03\t 4 - Alterar Lâmpada 04")
    print("|5 - Alterar Ar 01\t 6 - Alterar Ar 02")
    print("|7 - Atualizar Interface")
    print("|8 - Definir Temperatura de Referência")
    print("|0 - Sair")
    print("------------------------------------------------")


    if data:
        print(data)