#!/usr/bin/python3

screen_to = screen_from = None
output = result_update = ""
from_name = to_name = "Celsius"
in_mes = out_mes = 1

mes_names =[
    "Celsius", "Kelvin", "Fahrenheit"]

def temperature_window():
    from data import tk, temperature_btn, temperature_indicator
    from data import setup_page

    global screen_to, screen_from, result_update, mes_names

    def temperature_convert(n):
        global from_name, to_name
        if from_name == to_name:
            return str(n)

        elif from_name == "Celsius":
            # Celsius --> Kelvin
            if to_name == "Kelvin":
                return str(n + 273.15)
            # Celsius --> Fahrenheit
            elif to_name == "Fahrenheit":
                return str((9/5) * n + 32)

        elif from_name == "Kelvin":
            # Kelvin --> Celsius
            if to_name == "Celsius":
                return str(n - 273.15)
            # Kelvin --> Fahrenheit
            elif to_name == "Fahrenheit":
                return str((9/5) * (n - 273.15) + 32)

        elif from_name == "Fahrenheit":
            # Fahrenheit --> Celsius
            if to_name == "Celsius":
                return str((5/9) * (n - 32))
            # Fahrenheit --> Kelvin
            elif to_name == "Kelvin":
                return str((5/9) * (n - 32) + 273.15)


    # This function checkes the input if it is in teh correct format
    def validation(input):
        global in_mes, out_mes, output, screen_to, result_update, from_name, to_name
        result_line = ""
        try:
            number = eval(input)
            output = temperature_convert(number)
            result_line = "Result: {} {} = {} {}".format(input, from_name,output, to_name)
            result_update.config(fg="black")
        except (SyntaxError, NameError):
            output = ""
            if input:
                result_line = "Error"
                result_update.config(fg="red")
        
        insert(screen_to, output)
        insert(result_update, result_line)
    ################################################################
        
    ################################################################
    def listSelected(event, name):
        global in_mes, out_mes, mes_list, screen_from, from_name, to_name
        box = event.widget
        try:
            i = box.curselection()[0]
            if name == "from":
                in_mes = mes_list[i]
                from_name = mes_names[i]
            elif name == "to":
                out_mes = mes_list[i]
                to_name = mes_names[i]
            for index in range(box.size()):
                if index == i:
                    box.itemconfig(index, bg="#BDA8A8")
                else:
                    box.itemconfig(index, bg="white")
        except Exception:
            pass
        validation(screen_from.get())
    ################################################################
        
    ################################################################
    def listSelected(event, name):
        global in_mes, out_mes, mes_list, screen_from, from_name, to_name
        box = event.widget
        try:
            i = box.curselection()[0]
            if name == "from":
                in_mes = mes_list[i]
                from_name = mes_names[i]
            elif name == "to":
                out_mes = mes_list[i]
                to_name = mes_names[i]
            for index in range(box.size()):
                if index == i:
                    box.itemconfig(index, bg="#BDA8A8")
                else:
                    box.itemconfig(index, bg="white")
        except Exception:
            pass
        validation(screen_from.get())
    #################################################################
        
    #################################################################
    def insert(screen, msg):
        screen.config(state="normal")
        screen.delete(0, "end")
        screen.insert(0, msg)
        screen.config(state="readonly")
    #################################################################
    

    screen = setup_page(temperature_btn, temperature_indicator)
    screen.columnconfigure(0, weight=1)
    screen.columnconfigure(1, weight=1)

    from_l = tk.Label(screen, text="From:", font=("Arial", 18), anchor="w", padx=20)
    from_mesurments = tk.StringVar(value=mes_names)
    from_box = tk.Listbox(screen, selectmode=tk.SINGLE, font=("Arial", 15),
                          highlightthickness=0, listvariable=from_mesurments,
                          selectbackground="#BDA8A8", borderwidth=0, selectborderwidth=0)
    from_box.grid(row=2, column=0, sticky="nesw", padx=(6, 3), pady=(0, 6))
    from_l.grid(row=0, column=0, sticky="nesw")

    to_l = tk.Label(screen, text="To:", font=("Arial", 18), anchor="w", padx=20)

    #################################################

    to_mesurments = tk.StringVar(value=mes_names)
    to_box = tk.Listbox(screen, selectmode=tk.SINGLE, font=("Arial", 15),
                          highlightthickness=0, listvariable=to_mesurments,
                          selectbackground="#BDA8A8")

    to_box.grid(row=2, column=1, sticky="nesw", padx=(3, 6), pady=(0, 6))
    to_l.grid(row=0, column=1, sticky="nesw")

    #################################################

    screen_from = tk.Entry(screen, font=("Arial", 20), bd=10, relief=tk.FLAT)
    screen_from.bind('<KeyRelease>', lambda event: validation(event.widget.get()))
    screen_from.grid(row=1, column=0, sticky=tk.W+tk.E, pady=6, padx=(6, 3))


    screen_to = tk.Entry(screen, font=("Arial", 20), bd=10, relief=tk.FLAT, state="readonly", readonlybackground="#DFDFDF")
    screen_to.grid(row=1, column=1, sticky=tk.W+tk.E, pady=6, padx=(3, 6))

    from_box.bind('<<ListboxSelect>>', lambda event: listSelected(event, "from"))
    to_box.bind('<<ListboxSelect>>', lambda event: listSelected(event, "to"))

    result_update = tk.Entry(screen, font=("Helvetica", 20), relief=tk.FLAT, state="readonly", readonlybackground="white", justify="center")
    result_update.grid(row=3, columnspan=2, sticky="nesw", padx=6)