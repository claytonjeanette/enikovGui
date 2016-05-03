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

GPIO.output(23, GPIO.LOW)

def toggle_z_back():
    GPIO.output(23, GPIO.HIGH)

def toggle_z_forward():
    GPIO.output(23,GPIO.LOW)

GPIO.output(23, GPIO.LOW)

win.title('Spinner GUI')
win.geometry('800x480')

#spinneret rate buttons
button_increase_rate = tk.Button(win, text = 'Increase Rate', command = increase_rate)
button_increase_rate.grid(row=4, rowspan=2, column=1)

button_decrease_rate = tk.Button(win, text = 'Decrease Rate', command = decrease_rate)
button_decrease_rate.grid(row= 6, rowspan=2, column=1)

#Forward Backwards Button in Z direction
button_z_back = tk.Button(win, text = 'Back Z', command = toggle_z_back)
button_z_back.grid(row=2, column=2)

button_z_forward = tk.Button(win, text = 'ForwardZ', command = toggle_z_forward)
button_z_forward.grid(row=1, column=2)

# collection Plate Up/Down in X direction
button_x_up = tk.Button(win, text = 'Up', command = toggle_up)
button_x_up.grid(row=1, column=3)

button_x_down = tk.Button(win, text = 'Down', command = toggle_down)
button_x_down.grid(row=2, column=3)

#collection Plate Left Right y direction
button_y_left = tk.Button(win, text ='Left', command = toggle_left)
button_y_left.grid(row=4, column=2)

button_y_right = tk.Button(win, text = 'Right', command = toggle_right)
button_y_right.grid(row=4, column=3)

#loop functions to prevent automatic exiting
win.mainloop()
