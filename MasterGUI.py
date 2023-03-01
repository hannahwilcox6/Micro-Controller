# --------------- #
# Team Rocket 2023
# Master GUI
# just for the GUI build out calls different files for commands

# General Imports
from tkinter import *
from tkinter import ttk
import RPi.GPIO as GPIO
from time import sleep

# hardware section imports
import Switches as switches

def softShutDown():
    pass

root = Tk()
frm = ttk.Frame(root, padding = 10)
frm.grid()
ttk.Label(frm, text = "Rocket Launcher").grid(column = 0, row = 0)

#Top level buttons for th begining of the window
ttk.Button(frm, text = "Quit", command = softShutDown()).grid(column = 2, row = 1)
ttk.Button(frm, text = "Help", command = softShutDown()).grid(column = 1, row = 1)

root.mainloop()

