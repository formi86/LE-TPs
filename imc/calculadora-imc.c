#include <stdio.h>

float imc;
char ok = 0;

struct data
{
    char nombre[20];
    char apellido[20];
    int dni;
    char email[320];
    float peso;
    int altura;
    int telefono;
};
struct data data1;

char checkValues(int dni, char email[320]) {
    for (int i = 0; i < 320; i++)
    {
        if (email[i] == 64) ok++; //@
        if (email[i] == 46 && email[i+1] == 99 && email[i+2] == 111 && email[i+3] == 109) ok++; //.com
    }

    if (ok == 2) return 1;
    else return 0;
    
}

void uploadValues(void) {
    printf("Ingrese el nombre: \n");
    scanf("%s", &data1.nombre);
    printf("Ingrese el apellido: \n");
    scanf("%s", &data1.apellido);
    printf("Ingrese el dni: \n");
    scanf("%d", &data1.dni);
    printf("Ingrese el email: \n");
    scanf("%s", &data1.email);
    printf("Ingrese el peso (en kg): \n");
    scanf("%f", &data1.peso);
    printf("Ingrese la altura (en cm): \n");
    scanf("%d", &data1.altura);
    printf("Ingrese el telefono: \n");
    scanf("%d", &data1.telefono);
}

float calcIMC(float peso, float altura) {
    altura = altura / 100;
    imc = peso / (altura* altura);
    return imc;
}

int main() {

    uploadValues();
    if (checkValues(data1.dni, data1.email)) printf("------- \n\nNombre: %s\nApellido: %s\nDNI: %d\nE-Mail: %s\nTelefono: %d\nIMC: %f \n", data1.nombre, data1.apellido, data1.dni, data1.email, data1.telefono, calcIMC(data1.peso, data1.altura));
    else printf("El email debe contener \"@\" y \".com\" o \".com.ar\" \n");

    printf("Press any key to continue...");  
    getch();
}