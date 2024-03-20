#!/usr/bin/python3

screen_to = screen_from = None
output = result_update = ""
from_name = to_name = "Meter"
in_mes = out_mes = 1

mes_list = [1, 1000, 0.01, 0.001, 0.000001, 1.E-9, 1609.35,
            0.9144, 0.3048, 0.0254, 9460660000000000]

mes_names =[
    "Meter", "Kilometer", "Centimeter", "Milimeter", "Micrometer",
    "Nanometer", "Mile", "Yard", "Foot", "Inch", "Light Year"]

def lenght_window():
    from data import tk, lenght_btn, lenght_indicator, setup_page

    global screen_to, screen_from, result_update, mes_names

    # This function checkes the input if it is in teh correct format
    def validation(input):
        global in_mes, out_mes, output, screen_to, result_update, from_name, to_name
        result_line = ""
        try:
            output = str(eval(input) * in_mes / out_mes)
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


    screen = setup_page(lenght_btn, lenght_indicator)
    screen.columnconfigure(0, weight=1)
    screen.columnconfigure(1, weight=1)
    #################################################
    
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
