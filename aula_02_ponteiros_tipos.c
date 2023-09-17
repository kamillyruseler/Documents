#include <stdio.h>

int main(void){
    int x = 10;
    double y = 20.50;
    char z = 'a';

    // int *pX;
    // pX = &x; // Sem o asterisco, estamos acessando o endereço do ponteiro pX
    //  Nesse caso, está apontando no endereço de x

    int *pX = &x;
    double *pY = &y;
    char *pZ = &z;

    double soma = *pX + *pY;

    printf("Endereço x = %i - Valor x = %i \n", pX, *pX);
    // Quando eu não coloco o asterisco, estou puxando o endereço
    printf("Endereço Y = %i - Valor y = %f \n", pY, *pY);
    printf("Endereço Z = %i - Valor z = %c \n", pZ, *pZ);
    printf("Soma = %f", soma);

    getchar();
    return 0;
}