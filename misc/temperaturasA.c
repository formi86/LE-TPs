#include <stdio.h>
int cont, i = 0;
float temp[];

int main() {
    do
    {
        printf("Ingrese el valor de la temperatura\n");
        scanf("%f", &temp[i]);
        i++;
        printf("Continuar? 1: Si, 0:No \n");
        scanf("%d", &cont);
    } while (cont);

    for (int j = 0; j < i; j++)
    {
        printf("%f\n", temp[j]);
    }
    printf("Press any key to continue...");  
    getch();
}