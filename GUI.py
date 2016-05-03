try:
    # for for Python 2
    import Tkinter as tk
except ImportError:
    import tkinter as tk

import RPi.GPIO as GPIO
from time import sleep

#import tkFonts
#import tkMessageBox

GPIO.setmode(GPIO.BCM)

GPIO.setup(23, GPIO.OUT, initial = 0)
GPIO.setup(24, GPIO.OUT, initial = 0)
GPIO.setup(25, GPIO.OUT, initial = 0)

GPIO.output(23, GPIO.LOW)
GPIO.output(24, GPIO.LOW)
GPIO.output(25, GPIO.LOW)


def toggle_z_on():
    GPIO.output(23, GPIO.HIGH)
    # time.sleep(1)
    # GPIO.output(23, GPIO.LOW)


def toggle_z_off():
    GPIO.output(23,GPIO.LOW)
    # time.sleep(1)
    # GPIO.output(23, GPIO.LOW)

# def increase_rate():
#     GPIO.output(23,GPIO.LOW)
#     time.sleep(1)
#     GPIO.output(23, GPIO.LOW)

# def decrease_rate():
#     GPIO.output(23,GPIO.LOW)
#     time.sleep(1)
#     GPIO.output(23, GPIO.LOW)

def toggle_up_on():
    GPIO.output(23, GPIO.HIGH)
    GPI).output(25, GPIO.HIGH)
    # time.sleep(1)
    # GPIO.output(23, GPIO.LOW)
    # GPI).output(25, GPIO.LOW)

def toggle_up__off():
    GPIO.output(23, GPIO.LOW)
    GPIO.output(25, GPIO.LOW)
    # time.sleep(1)
    # GPIO.output(23, GPIO.HIGH)
    # GPIO.output(25, GPIO.HIGH)

def toggle_LeftRight():
    GPIO.output(25,GPIO.HIGH)
    GPIO.output(24,GPIO.HIGH)
    # time.sleep(1)
    # GPIO.output(25, GPIO.LOW)
    # GPIO.output(24,GPIOLOW)

def toggle_LeftRight_off():
    GPIO.output(24,GPIO.LOW)
    GPIO.output(25,GPIO.LOW)
    # time.sleep(1)
    # GPIO.output(24, GPIO.HIGH)
    # GPIO.output(25,GPIO.HIGH)



win.title('Spinner GUI')
win.geometry('800x480')

#spinneret rate buttons
button_increase_rate = tk.Button(win, text = 'Increase Rate', command = increase_rate)
button_increase_rate.grid(row=4, rowspan=2, column=1, columnspan=1)

button_decrease_rate = tk.Button(win, text = 'Decrease Rate', command = decrease_rate)
button_decrease_rate.grid(row= 6, rowspan=2, column=1, columnspan=1)

#Forward Backwards Button in Z direction
button_z_back = tk.Button(win, text = 'Back/Forward ON', command = toggle_z_on)
button_z_back.grid(row=2, rowspan=1, column=2, columnspan=1)

button_z_forward = tk.Button(win, text = 'Back/Forward OFF', command = toggle_z_off)
button_z_forward.grid(row=1, rowspan=1, column=2, column=1)

# collection Plate Up/Down in X direction
button_x_up = tk.Button(win, text = 'Up/Down ON', command = toggle_up_on)
button_x_up.grid(row=1, rowspan=2, column=3, columnspan=1)

button_x_off = tk.Button(win, text = 'Y OFF', command = toggle_up__off)
button_x_off.grid(row=1, rowspan=2, column=3, columnspan=1)

#collection Plate Left Right y direction
button_y_left = tk.Button(win, text ='Left/Right ON', command = toggle_LeftRight)
button_y_left.grid(row=4, rowspan=1, column=2, column=1)

button_y_right = tk.Button(win, text = 'LeftRight OFF', command = toggle_LeftRight_off)
button_y_right.grid(row=4, rowspan=1, column=3, columnspan=1)

#loop functions to prevent automatic exiting
win.mainloop()
