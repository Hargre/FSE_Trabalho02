from control import trigger_alarm

def process_command(command, state):
    if command.strip() == "ALARM":
        trigger_alarm(state)