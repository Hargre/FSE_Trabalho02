from control import trigger_alarm

def process_command(command):
    if command == "ALARM":
        trigger_alarm()