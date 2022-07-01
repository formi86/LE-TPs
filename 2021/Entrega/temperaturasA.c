/*

    ---PROGRAMA DE TEMPERATURAS CON ARRAYS---

    Consigna: Desarrollar un programa al que se le ingresan diferentes temperaturas, las guarda en un array y devuelve: la temperatura maxima, la temperatura minima, la cantidad temperaturas entre 10 y 20 grados, y el promedio de las temperaturas.
    
    Contenido aprendido: Utilizacion de arrays para almacenar variables de un mismo tipo.

    Codigo: *la funcionalidad es igual a la de temperaturas sin arrays, lo que cambia es que primero guardo las temperaturas ingresadas en un array llamado temp[], y despues con un ciclo "for" itero sobre cada elemento del array (temperatura ingresada) para hacer la evaluacion de si es maximo, minimo, etc.

*/



#include <stdio.h>
int max, min, tmp_between, i = 0;
float temp[], avg, sum;

int main() {
    do
    {
        printf("Ingrese el valor de la temperatura\n");
        scanf("%f", &temp[i]); //agrego el valor ingresado al array de temperaturas
        i++;
        printf("Continuar? y/n \n");
    } while (getch() != 'n');

    printf("Temperaturas ingresadas: ");
    for (int j = 0; j < i; j++) //itero sobre cada elemento del array de temperaturas (cada temperatura ingresada) para evaluar cada uno
    {
        printf("%f / ", temp[j]);
        if(!j) {
            max = temp[j];
            min = temp[j];
        } else {
            if (min > temp[j]) min = temp[j];
            if (max < temp[j]) max = temp[j];
        }
        if (temp[j] > 10 && temp[j] < 20) tmp_between++;
        sum += temp[j];
    }
    avg = sum/i;

    printf("\nMaximo: %d, Minimo: %d, Temperaturas entre 10 y 20: %d, Promedio: %f\n", max, min, tmp_between, avg);
    printf("Press any key to continue...");  
    getch();
}