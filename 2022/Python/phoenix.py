import pandas as pd
from tkinter import *
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg)


fig, ax = plt.subplots()


def select():
    x = df.get([option.get()])
    ax.clear()
    ax.hist(x, bins=20, linewidth=0.1, edgecolor="white")
    ax.set(xlabel='Terminal', ylabel='Veces que se usó',
           title='Uso de cada terminal')

    plt.yscale(scale.get())
    canvas.draw()


data = pd.read_csv('./datasets/phoenix-2017-flights.csv')
df = pd.DataFrame(data)
df.fillna(0)


root = Toplevel()

scale = StringVar()
option = StringVar()

Radiobutton(root, text="Lineal", variable=scale, value='linear',
            command=select).pack(side=LEFT)
Radiobutton(root, text="Logaritmica", variable=scale,
            value='log', command=select).pack(side=LEFT)
Radiobutton(root, text="Logaritmica simetrica", variable=scale,
            value='symlog', command=select).pack(side=LEFT)
Radiobutton(root, text="Terminal", variable=option, value='Terminal',
            command=select).pack(side=RIGHT)
Radiobutton(root, text="Arrivos o Partidas", variable=option,
            value='Arrive or Depart', command=select).pack(side=RIGHT)
Radiobutton(root, text="Aerolinea", variable=option,
            value='Airline', command=select).pack(side=RIGHT)


canvas = FigureCanvasTkAgg(fig, master=root)
canvas.get_tk_widget().pack(side=BOTTOM, fill=BOTH, expand=False)

root.mainloop()
