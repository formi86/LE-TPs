#include <stdio.h>
#define PI 3.14159
int main(){
    float radio;
    float circ;
    float area;

    scanf("%f", &radio);
    area = PI * radio * radio;
    circ = PI * radio * 2;
    
    return 0;
}