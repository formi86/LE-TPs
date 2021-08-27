#include <stdio.h>
int sum = 0;
int product = 0;
int main(){

    for (int i = 1; i <= 33; i++)
    {
        product = 3 * i ;
        printf("%d\n", product);
        sum += product;
    }
    printf("%d\n", sum);
    printf("Press any key to continue...");  
    getch();
    return 0;
}