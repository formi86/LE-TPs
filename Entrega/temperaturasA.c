#include <stdio.h>
int max, min, tmp_between, i = 0;
float temp[], avg, sum;

int main() {
    do
    {
        printf("Ingrese el valor de la temperatura\n");
        scanf("%f", &temp[i]);
        i++;
        printf("Continuar? y/n \n");
    } while (getch() != 'n');

    printf("Temperaturas ingresadas: ");
    for (int j = 0; j < i; j++)
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