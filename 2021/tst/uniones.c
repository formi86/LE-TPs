#include <stdio.h>

union
{
    float value;
    unsigned char bytes[4];
}var;

int main(){
    var.bytes[0] = 0x00;
    var.bytes[1] = 0x00;
    var.bytes[2] = 0x40;
    var.bytes[3] = 0x40;
    printf("%f", var.value);
}