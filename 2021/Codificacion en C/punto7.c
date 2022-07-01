#include <stdio.h>

int main(){
    int num;
    printf("Escriba el numero:\n", "hola");
    scanf("%d", &num);
    printf("El numero es %s\n", num%2 ? "impar" : "par");
    printf("Press any key to continue..."); 
    getch();
    return 0;
}