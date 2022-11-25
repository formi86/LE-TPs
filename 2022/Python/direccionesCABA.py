'''
    Este programa lo hice para probar el random de numpy
    Me di cuenta que si juntas 2 nombres random de provincias, paises, lugares, personas, etc podes formar lo que podria llegar a ser 
    una direccion en capital, entonces lo hice.
    
'''

import numpy as np
import msvcrt as m
import pandas as pd

# ? Creo llas tuplas con todos los nombres que puedo llegar a usar
provicias = ('La Pampa', 'Santa Fe', 'Cordoba', 'Mendoza',
             'Tucuman', 'Santiago del Estero', 'Corrientes', 'Misiones', 'San Juan')

paises = ('Brasil', 'Uruguay', 'Paraguay', 'Peru',
          'Ecuador', 'Chile', 'Bolivia', 'Venezuela', 'Mexico', 'Estados Unidos', 'Austria', 'Honduras', 'El Salvador')

lugares = ('Salta', 'Ituzaingo', 'Cochabamba', 'Callao',
           'Portela', 'Montevideo', 'Parana', 'Junin', 'Quito', 'Uspallata', 'Rio de Janeiro', 'Rafaela', 'Pergamino', 'Maipu', 'Suipacha', 'Chacabuco')

dias = ('3 de Febrero', '9 de Julio', '25 de Mayo')

personas = ('Lavalle', 'Figeroa Alcorta', 'Hipolito Yrigoyen', 'Sarmiento', 'Bouchard',
            'Pelegrini', 'Arenales', 'Bolivar', 'San Martin', 'Moreno', 'Belgrano', 'Solis', 'Rodriguez Peña', 'Mitre', 'Azcuenaga', 'Pasteur', 'Viamonte', 'Alsina', 'Lavalle', 'Uriburu', 'Alvear', 'Alberdi', 'Rivadavia', 'Dorrego')

conceptos = ('Saraza', 'Libertad', 'Independencia',
             'Piedras', 'Juncal', 'Vuelta de Obligado', 'Reconquista', 'Cabildo', 'Esmeralda', 'Constitucion', 'Defensa', 'Av de Mayo', 'Paseo del Bajo', 'La Via')

all = (provicias, paises, lugares, dias, personas, conceptos)


def getRealSt():
    # ? Leo el dataset con las calles de CABA reales
    df = pd.read_csv('./datasets/callejero.csv')
    df.dropna(axis=0)
    names = df.get(['nom_mapa'])
    x = np.random.randint(len(names), size=2)
    indexA = x[0]
    indexB = x[1]
    if (indexA == indexB):
        indexA = round(indexA / 2)

    streetA = str(names.iloc[indexA]['nom_mapa'])
    streetB = str(names.iloc[indexB]['nom_mapa'])
    street = (streetA, streetB)
    return street


def getFakeSt():
    x = np.random.randint(500, size=2)

    indexA1 = x[0] % 6
    indexA2 = x[1] % len(all[indexA1])
    streetA = all[indexA1][indexA2]

    indexB1 = x[1] % 6
    indexB2 = x[0] % len(all[indexB1])
    streetB = all[indexB1][indexB2]

    if (streetA == streetB):
        streetB = all[4][indexB2]

    street = (streetA, streetB)
    return street


print(f'Ver calle geteada del dataset o calle geteada de las tuplas? \n1: Dataset\n2: Tuplas\n')
opt = m.getch().decode('ASCII')

# ? Hasta que el usuario me diga que no quiere seguir generando nombres de calles no paro
while 1:
    if (opt == '1'):
        street = getRealSt()
    elif (opt == '2'):
        street = getFakeSt()

    if (street[1][0] == "I" or (street[1][0] == "H" and street[1][1] == "i")):
        con = "e"
    else:
        con = "y"

    print(f'Estoy en {street[0]} {con} {street[1]} \nDenuevo? y/n ')
    if (m.getch().decode('ASCII') != 'y'):
        break
