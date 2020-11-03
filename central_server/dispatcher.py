from control import trigger_alarm

def process_command(command, state):
    if command.strip('\x00') == 'ALARM':
        trigger_alarm(state)