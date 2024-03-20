#!/usr/bin/python3

import tkinter as tk
from data.lenght import lenght_window
from data.temperature import temperature_window
from data.area import area_window
from data.volume import volume_window
from data.time import time_window
from data.weight import weight_window
 
root = tk.Tk()
root.title("Unit converter")
root.geometry("600x453")
root.configure(bg="#B2B2B2")

def clear_indicators():
    for indicator in [lenght_indicator, temperature_indicator, area_indicator,
                volume_indicator, weight_indicator, time_indicator]:
        indicator['bg'] = "#DADADA"


def switch_indicator(btn, indicator):
    global current_btn
    clear_indicators()
    indicator['bg'] = "#9E1A46"
    current_btn.configure(state="normal", bg="#DADADA")
    btn.configure(state="disabled", disabledforeground="black", bg="#A6A6A6")

#################################################################
def setup_page(btn, indicator):
    global current_page, current_btn
    if current_page:
        current_page.destroy()
    switch_indicator(btn, indicator)
    current_page = tk.Frame(window, bg="#797979")
    current_page.pack(fill=tk.BOTH, expand=True)
    current_btn = btn
    return current_page
    #############################################################

top_bar = tk.Frame(root, bg="#515151")
for i in range(6):
    top_bar.columnconfigure(i, weight=1)
top_bar.grid_rowconfigure(1, weight=1)

#################################################
#                 Lenght Button
#################################################
lenght_btn = tk.Button(top_bar, text="lenght", font=("Bold", 12), relief=tk.FLAT, height=2,
                   activebackground="#A6A6A6", bd=0, bg="#DADADA",
                   command=lambda: lenght_window())
lenght_btn.grid(row=0, column=0, sticky="nesw")

lenght_indicator = tk.Label(lenght_btn, bg="#9E1A46")
lenght_indicator.place(y=45, width=1000, height=5)
#################################################
#               Temperature Button
#################################################
temperature_btn = tk.Button(top_bar, text="temperature", font=("Bold", 12), relief=tk.FLAT,
                   activebackground="#A6A6A6", bd=0, bg="#DADADA",
                   command=lambda: temperature_window())
temperature_btn.grid(row=0, column=1, sticky="nesw")

temperature_indicator = tk.Label(temperature_btn)
temperature_indicator.place(y=45, width=1000, height=5)
#################################################
#                 Area Button
#################################################
area_btn = tk.Button(top_bar, text="area", font=("Bold", 12), relief=tk.FLAT,
                   activebackground="#A6A6A6", bd=0, bg="#DADADA",
                   command=lambda: area_window())
area_btn.grid(row=0, column=2, sticky="nesw")

area_indicator = tk.Label(area_btn)
area_indicator.place(y=45, width=1000, height=5)
#################################################
#                Volume Button
#################################################
volume_btn = tk.Button(top_bar, text="volume", font=("Bold", 12), relief=tk.FLAT,
                   activebackground="#A6A6A6", bd=0, bg="#DADADA",
                   command=lambda: volume_window())
volume_btn.grid(row=0, column=3, sticky="nesw")

volume_indicator = tk.Label(volume_btn)
volume_indicator.place(y=45, width=1000, height=5)
#################################################
#                weight Button
#################################################
weight_btn = tk.Button(top_bar, text="weight", font=("Bold", 12), relief=tk.FLAT,
                   activebackground="#A6A6A6", bd=0, bg="#DADADA",
                   command=lambda: weight_window())
weight_btn.grid(row=0, column=4, sticky="nesw")

weight_indicator = tk.Label(weight_btn)
weight_indicator.place(y=45, width=1000, height=5)
#################################################
#                time Button
#################################################
time_btn = tk.Button(top_bar, text="time", font=("Bold", 12), relief=tk.FLAT,
                   activebackground="#A6A6A6", bd=0, bg="#DADADA",
                   command=lambda: time_window())
time_btn.grid(row=0, column=5, sticky="nesw")

time_indicator = tk.Label(time_btn)
time_indicator.place(y=45, width=1000, height=5)
#################################################
top_bar.pack(side=tk.TOP, fill=tk.X)
top_bar.pack_propagate(False)

# The window
window = tk.Frame(root, bg="#F0F0F0")
window.pack(fill=tk.BOTH, expand=True)

# Set the current Button to the home button (lenght button)
current_btn = lenght_btn
# Set the current Page to the home page (lenght converter)
current_page = None