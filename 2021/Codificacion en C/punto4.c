#include <stdio.h>
#define PI 3.14159
int main(){
    float radio;
    float circ;
    float area;
    printf("Introduzca el radio del circulo:\n");
    scanf("%f", &radio);
    area = PI * radio * radio;
    circ = PI * radio * 2;

    printf("Area: %f\nCircunferencia:%f\n", area, circ);
    printf("Press any key to continue...");  
    getch();
    return 0;
}