#include <stdio.h>
int main(){
    float numero;
    int mayor = 0;
    int menor = 0;

    for(int i = 0; i < 10; i++) {
        printf("Introduzca el numero %d\n", i+1);
        scanf("%f", &numero);
        if(numero > 0){
            mayor++;
        } else if (numero < 0) {
            menor++;
        }
    }
    printf("Mayores a 0: %d\nMenores a 0: %d\n", mayor, menor);
    printf("Press any key to continue...");  
    getch();
    return 0;
}