/*

    ---VISUALIZADOR DE CONTENIDO DE VARIABLE DE PUNTO FLOTANTE---

    - Consigna: Desarrollar un programa que visualice el contenido guardado en memoria de una variable de punto flotante utilizando punteros y estructuras. 
    
    - Contenido aprendido: Utilizacion de punteros y uniones para visualizar los contenidos de una variable almecenada en memoria.
    
    - Explicacion: 
        - Punteros: los punteros son unos tipos de variables que contienen la direccion en memoria de otra variable (a la que apuntan), en este codigo, el puntero hace que podamos ver el contenido de la direccion de memoria 
                    donde comienza la variable de punto flotante, y como esta ocupa 4 bytes, tambien podemos ver el contenido de las 3 direcciones de memoria siguientes, y asi visualizar todo el contenido de la variable de punto flotante.
        - Uniones: las uniones son unos tipos de estructuras en las que sus elementos comparten la direccion de memoria, en este caso nos sirve porque al cambiar el valor de "value" que es una variable de punto flotante 
                   (como la que nos ingresa el usuario), tambien cambiamos el valor de el array de bytes bytes[], el cual al imprimirlo, nos va a mostrar el contenido de cada direccion de memoria destinada a guardar la variable que seteamos como "value".

    - Codigo:
*/

#include <stdio.h>

union { //declaro una union, la cual voy a usar para almacenar el valor de la variable de punto flotante ingresada, y despues leer el contenido con el array bytes[4]
    float value;
    unsigned char bytes[4];
}var; //creo una instancia de la union llamada var


char utilizar, continuar;
float num; 

int main(){
    do
    {
        printf("Escriba el numero de tipo flotante\n");
        scanf("%f", &num);
        printf("Desea ver el contenido de un flotante utilizando:\n1. Punteros\n2. Estructuras(uniones)\n");
        scanf("%d", &utilizar);
        unsigned char *p=(unsigned char *)&num; //creo un puntero que apunte a la variable num (el numero ingresado)

        switch (utilizar) {
            case 1:         
                printf("Contenido visualizado utilizando punteros:\n");
                for(int i = 0; i < 4; i++) printf("0x%x\n", *(p+i)); //con el ciclo for, itero entre el contenido en las 4 direcciones de memoria destinadas a almacenar la variable num, y lo imprimo
                break;

            case 2:
                var.value = num; //seteo el valor de la instancia de la union var igual al numero ingresado
                printf("Contenido visualizado utilizando estructuras(uniones):\n");
                for(int i = 0; i < 4; i++) printf("0x%x\n", var.bytes[i]); //con el ciclo for, itero entre el contenido de las 4 direcciones de memoria que almacenan el valor antes ingresado de la union "var" 
                break;

            default:
                printf("Introduzca alguno de los numeros solicitados \n\a"); // \a hace que suene un beep
                break;
        }
        printf("Continuar? y/n\n");
    } while (getch() != 'n');

    return 0;
}