/*

    ---PROGRAMA DE TEMPERATURAS---

    - Consgina: Desarrollar un programa al que se le ingresan diferentes temperaturas y devuelve: la temperatura maxima, la temperatura minima, la cantidad temperaturas entre 10 y 20 grados, y el promedio de las temperaturas.
    
    - Codigo:
*/


#include <stdio.h>
float tmp, avg, sum = 0;
int max, min, i = 0, tmp_between, cont;

int main() {
    do
    {
        printf("Ingrese el valor de la temperatura\n");
        scanf("%f", &tmp);
        if(!i) { //si es la primera temperatura que ingresa, esta sera la maxima y la minima
            max = tmp;
            min = tmp;
        } else {
            if (min > tmp) min = tmp; //si la temperatura ingresada es menor que la minima registrada, pasara a ser la nueva temperatura minima
            if (max < tmp) max = tmp; //si la temperatura ingresada es mayor que la maxima registrada, pasara a ser la nueva temperatura maxima
        }
        if (tmp > 10 && tmp < 20) tmp_between++; //si el valor de la temperatura ingresada esta entre 10 y 20, le sumo 1 al contador de temperaturas entre 10 y 20
        sum += tmp; //sumo la temperatura ingresada al la variable de la suma de temperaturas ingresadas que luego uso para calcular el promedio
        i++;
        printf("Continuar? y/n \n");
    } while (getch() != 'n');

    avg = sum/i; //divido la suma de todas las temperaturas por la cantidad de temperaturas ingresadas para conseguir el promedio

    printf("Maximo: %d, Minimo: %d, Temperaturas entre 10 y 20: %d, Promedio: %f\n", max, min, tmp_between, avg);
    printf("Press any key to continue...");  
    getch();
}