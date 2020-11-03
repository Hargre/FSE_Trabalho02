from control import trigger_alarm

def process_command(command, state):
    if int(command) == 1:
        trigger_alarm(state)