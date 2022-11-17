'''
    Este simple programa es para probar casos de la conjetura de Collatz
    Hay un video muy interesante donde se explica de que trata: https://www.youtube.com/watch?v=eHmee564FMo&t=536s&ab_channel=TheWildProject

'''

x = int(input("Ingrese su numero inicial: \n"))
y = x
z = y

while x != 4 or y != 1 or z != 2:
    print("\n" + str(round(x)) + "\n\n")
    if (x % 2):
        z = y
        y = x
        x = 3 * x + 1
    else:
        z = y
        y = x
        x /= 2
