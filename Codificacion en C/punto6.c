#include <stdio.h>

int main(){
    float num;
    printf("Introduzca el numero:\n");
    scanf("%f", &num);
    if(num < 0) {
        printf("El numero es negativo\n");
    } else if (num > 0) {
        printf("El numero es positivo\n");
    } else {
        printf("El numero es 0");
    }
    printf("Press any key to continue...");  
    getch();
    return 0;
}