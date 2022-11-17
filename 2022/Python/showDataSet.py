'''
    Este programa te permite visualizar cada columna de un dataset, el cual vos seleccionas, como un histograma.
    No todos los datos en las columnas son compatibles con el grafico de tipo histograma

'''


import pandas as pd
from tkinter import *
from tkinter import filedialog as fd
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


# ? Creo el dataframe a partir del archivo seleccionado y lleno los NaN con 0
fileName = fd.askopenfilename()
data = pd.read_csv(fileName)
df = pd.DataFrame(data)
df.fillna(0)
columns = df.columns

fig, ax = plt.subplots()


def select():
    # ? Actualizar canvas con escala u opcion nueva
    opt = option.get()
    x = df.get([opt])
    ax.clear()
    ax.hist(x, bins=20, linewidth=0.1, edgecolor="white")
    ax.set(xlabel=opt, ylabel='Cantidad en dataset',
           title='Cantidad de cada '+opt)

    plt.yscale(scale.get())
    canvas.draw()


# ? Crear TopLevel de tkinter y las variables que va a usar
top = Toplevel()
scale = StringVar(None, "linear")
option = StringVar(None, "Arrive or Depart")


# ? Texto informativo
Label(top, text='⚠️No todos los tipos de escala y no todos las columnas del dataset son compatibles con el grafico de tipo histograma⚠️').pack(side=TOP)


# ? Botones para definir la escala
Radiobutton(top, text="Lineal", variable=scale, value='linear',
            command=select).pack(side=LEFT)
Radiobutton(top, text="Logaritmica", variable=scale,
            value='log', command=select).pack(side=LEFT)
Radiobutton(top, text="Logaritmica simetrica", variable=scale,
            value='symlog', command=select).pack(side=LEFT)


# ? Botones para seleccionar la caracteristica a mostrar
for col in columns:
    Radiobutton(top, text=col, variable=option, value=col,
                command=select).pack(side=BOTTOM)


# ? Mostrar Canvas de matplotlib
canvas = FigureCanvasTkAgg(fig, master=top)
canvas.get_tk_widget().pack(side=BOTTOM, fill=BOTH, expand=False)


# ? Cerrar el programa si la ventana se cierra
top.protocol("WM_DELETE_WINDOW", exit)


top.mainloop()
