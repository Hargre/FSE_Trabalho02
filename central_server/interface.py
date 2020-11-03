import os
from enum import Enum

class MenuOptions(Enum):
    REFRESH_INTERFACE = 7
    INPUT_REF_TEMPERATURE = 8
    TOGGLE_ALARM = 9
    EXIT = 0

def refresh_menu(data):
    os.system('clear')
    print("--------- Servidor Central - Comandos ----------")
    print("|1 - Alterar Lâmpada 01\t 2 - Alterar Lâmpada 02")
    print("|3 - Alterar Lâmpada 03\t 4 - Alterar Lâmpada 04")
    print("|5 - Alterar Ar 01\t 6 - Alterar Ar 02")
    print("|7 - Atualizar Interface")
    print("|8 - Definir Temperatura de Referência")
    print("|9 - Ativar/Desativar Alarme")
    print("|0 - Sair")
    print("------------------------------------------------")


    if data:
        print(data)

def input_loop(state):
    option = int(input())

    while option != MenuOptions.EXIT.value:
        if option == MenuOptions.REFRESH_INTERFACE.value:
            refresh_menu(state)
        elif option == MenuOptions.INPUT_REF_TEMPERATURE.value:
            print("Digite a temperatura de referência:")
            state.ref_temperature = float(input())
            refresh_menu(state)
        elif option == MenuOptions.TOGGLE_ALARM.value:
            result = state.toggle_alarm()
            if not result:
                print("Não foi possível ativar o alarme. Verifique portas, janelas e cômodos e tente novamente.")
        else:
            send_message(option)

        option = int(input())