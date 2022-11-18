'''
    Este simple programa es para probar casos de la conjetura de Collatz
    Hay un video muy interesante donde se explica de que trata: https://www.youtube.com/watch?v=eHmee564FMo

'''

x = int(input("Ingrese su numero inicial: "))
y = x
z = y
i = 0

while x != 4 or y != 1 or z != 2:
    print(str(round(x)))
    if (x % 2):
        z = y
        y = x
        x = 3 * x + 1
    else:
        z = y
        y = x
        x /= 2
    i += 1

print(
    f'\nSu numero termino en la secuencia 4, 2, 1 despues de la repeticion #{i} !')
