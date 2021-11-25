#include <stdio.h>
float tmp, avg, sum = 0;
int max, min, i = 0, tmp_between, cont;

int main() {
    do
    {
        printf("Ingrese el valor de la temperatura\n");
        scanf("%f", &tmp);
        if(!i) {
            max = tmp;
            min = tmp;
        } else {
            if (min > tmp) min = tmp;
            if (max < tmp) max = tmp;
        }
        if (tmp > 10 && tmp < 20) tmp_between++;
        sum += tmp;
        i++;
        printf("Continuar? y/n \n");
    } while (getch() != 'n');

    avg = sum/i;

    printf("Maximo: %d, Minimo: %d, Temperaturas entre 10 y 20: %d, Promedio: %f\n", max, min, tmp_between, avg);
    printf("Press any key to continue...");  
    getch();
}