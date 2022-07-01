/*
    ---CALCULADORA DE INDICE DE MASA CORPORAL (IMC)---

    - Consigna: Desarrollar un programa que calcule el IMC (indice de masa corporal), para esto debe guardar en una estructura, los siguientes datos: 
                Nombre, Apellido, DNI, email, edad, peso, altura y telefono. El software debe trabajar con una función que cargue los valores en la estuctura, 
                otra función que reciba el peso y la altura y devuelva el IMC para ser presentado en pantalla con una leyenda asociada a dicho IMC. Se deberá 
                chequear el que correo ingresado sea válido (es decir que contenga un '@' y termine en .com o .com.ar) y que el teléfono sea numérico.

    - Contenido aprendido: Utilizacion de Estructuras para almacenar datos y Arrays de caracteres para formar Strings
    
    - Codigo:
*/

#include <stdio.h>

float imc;
char ok = 0;

struct data //declaro una estructura para gurdar los datos
{
    char nombre[20];
    char apellido[20];
    int dni;
    char email[320];
    float peso;
    int altura;
    int telefono;
};
struct data data1; //creo una instancia de la estructura data llamada data1, data1 va a ser la variable que voy a usar

char checkValues(char email[320]) {
    //para checkear que el email ingresado contenga "@" y ".com" reviso todos los caracteres uno por uno
    for (int i = 0; i < 320; i++)
    {
        if (email[i] == 64) ok++; //si contiene @ le sumo 1 a ok
        if (email[i] == 46 && email[i+1] == 99 && email[i+2] == 111 && email[i+3] == 109) ok++; //si contiene .com le sumo 1 a ok
    }
    if (ok == 2) return 1; //si contiene @ y .com devuelvo un 1
    else return 0;
    
}

void uploadValues(void) {
    //guardo todos los valores ingresados en la instancia creada de la estructura data
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
    //IMC = peso / (altura/100)^2
    altura = altura / 100;
    imc = peso / (altura * altura);
    return imc;
}

int main() {
    uploadValues(); //llamo a la funcion para subir los valores
    if (checkValues(data1.email)) printf("------- \n\nNombre: %s\nApellido: %s\nDNI: %d\nE-Mail: %s\nTelefono: %d\nIMC: %f \n\n------- \n", data1.nombre, data1.apellido, data1.dni, data1.email, data1.telefono, calcIMC(data1.peso, data1.altura)); //si los valores ingresados son correctos, imprimo la informacion
    else printf("El email debe contener \"@\" y \".com\" o \".com.ar\" \n\a"); // \a hace que suene un beep

    printf("Press any key to continue...");  
    getch();
}