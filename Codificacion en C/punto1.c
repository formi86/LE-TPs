#include <stdio.h>
int main(){
    float numero;
    float suma = 0;
    float media = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("Introduzca el numero %d \n", i+1);
        scanf("%f", &numero);
        suma += numero;
    }
    media = suma / 5
    printf("La suma de los numeros es: %f\n La media de los numeros es: %f", suma, media);
}