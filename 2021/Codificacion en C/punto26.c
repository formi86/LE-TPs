#include <stdio.h>
#include <math.h>
#define PI 3.14159

float vp[2];
float ip[2];
float vb[2];
float ib[2];
float zp[2];
float zb[2];
float carga;

// float get_z(float vp[], float ip[]) {
//     zp[0] = vp[0] / ip[0];
//     zp[1] = vp[1] - ip[1];
//     zb[0] = zp[0] * cos(zp[1]);
//     zb[1] = zp[0] * sin(zp[1]);
//     z = {zp, zb}
//     return z
// }

int main(){

    printf("Modulo de V:\n");
    scanf("%f", &vp[0]);
    printf("Angulo de V:\n");
    scanf("%f", &vp[1]);
    printf("Modulo de I:\n");
    scanf("%f", &ip[0]);
    printf("Angulo de I:\n");
    scanf("%f", &ip[1]);

    zp[0] = vp[0] / ip[0];
    zp[1] = vp[1] - ip[1];
    zb[0] = zp[0] * cosf((zp[1]*PI)/180);
    zb[1] = zp[0] * sinf((zp[1]*PI)/180);
    
    printf("Z mod: %f\nZ ang: %f\n", zp[0], zp[1]);
    printf("Z real: %f\nZ imaginario: %f\n", zb[0], zb[1]);

    if (zb[1] == 0)
    {
        printf("La resistencia es de: %f ohms, no posee carga inductiva ni capacitiva", zb[0]);
    }
    else
    {   
        printf("Frecuencia: (solo numeros enteros)\n");
        int frec;
        scanf("%d", &frec);

        if (zb[1] < 0) {
            carga = -1/(2*PI*zb[1]*frec);
        }
        else {
            carga = zb[1]/(2*PI*frec);
        }
    }
    

    printf("La resistencia es de %f ohms, la carga %s es de %f %s", zb[0], zb[1]>0 ? "inductiva" : "capacitiva", carga, zb[1]>0 ? "henrios" : "faradios");

    printf("Press any key to continue...");  
    getch();
    return 0;
}