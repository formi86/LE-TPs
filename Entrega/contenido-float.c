#include <stdio.h>

char utilizar, continuar;
float miVar; 

int main(){
    
    do
    {
        printf("Escriba el numero de tipo flotante\n");
        scanf("%f", &miVar);
        printf("Desea ver el contenido de un flotante utilizando:\n1. Punteros\n2. Estructuras\n");
        scanf("%d", &utilizar);

        unsigned char *p=(unsigned char *)&miVar;
        switch (utilizar) {
            case 1:
                printf("Contenido visualizado utilizando punteros:\n");
                for(int i = 0; i < sizeof(miVar); i++) printf("0x%x\n", *(p+i));
                break;

            case 2:
                printf("Contenido visualizado utilizando estructuras:\n");
                for(int i = 0; i < sizeof(miVar); i++) printf("0x%x\n", p[i]);
                break;

            default:
                printf("Introduzca alguno de los numeros solicitados \n\a");
                break;
        }
        printf("Continuar? y/n\n");
    } while (getch() != 'n');

    return 0;
}