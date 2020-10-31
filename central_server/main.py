from server import send_message
from control import get_state

import curses
import locale
import threading

locale.setlocale(locale.LC_ALL, '')
code = locale.getpreferredencoding()

def main(stdscr):
    stdscr.noutrefresh()
    curses.doupdate()

    stdscr.addstr(1, 0,"1 - Alterar L01")
    stdscr.addstr(2, 0,"2 - Alterar L02")
    stdscr.addstr(3, 0,"3 - Alterar L03")
    stdscr.addstr(4, 0,"4 - Alterar L04")
    stdscr.addstr(5, 0,"0 - Sair")

    stdscr.noutrefresh()
    curses.doupdate()

    state_updates = threading.Thread(target=get_state,args=(stdscr,))
    state_updates.start()

    option = int(stdscr.getkey())

    while option != 0:
        send_message(option)
        option = int(stdscr.getkey())
    
    stop = True
    state_updates.join()
    stdscr.noutrefresh()
    curses.doupdate()
    curses.endwin()

if __name__ == '__main__':
    curses.wrapper(main)