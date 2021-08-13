#include <stdio.h>

int main(){
    float height;
    float base;
    float area;

    printf("Introduzca la altura del triangulo:\n");
    scanf("%f", &height);
    printf("Introduzca la base del triangulo:\n");
    scanf("%f", &base);
    area = (height * base) / 2;
    printf("El area del triangulo es de:%f\n", area);
    return 0;
}