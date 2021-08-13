#include <stdio.h>
int main(){
    float numero;
    do {
        printf("Introduzca el numero \n");
        scanf("%f", &numero);
        if(numero < 0) printf("ERROR, el número debe ser mayor que cero \n");
    } while (numero < 0);
    numero *= numero ;
    printf("El cuadrado del numero introducido es: %f\n", numero);
    return 0;
}