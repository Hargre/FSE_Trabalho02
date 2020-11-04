from control import trigger_alarm
from logger import Logger

def process_command(command, state):
    if command.strip('\x00') == 'ALARM':
        trigger_alarm(state)
        logger = Logger.get_instance()
        logger.log_alarm()
