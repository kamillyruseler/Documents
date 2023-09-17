#include <stdio.h>

int main(void)
{

    void testeVariavel(int x);
    void testePonteiro(int *pX);
    int teste = 1;
    int *pTeste = &teste;

    /*  testeVariavel(teste); // adiciona um valor à variável teste
        // porém, dessa maneira, não estará incrementando o valor corretamente.
        // continua printando 1, já que isso seria uma cópia da variável */

    testePonteiro(pTeste); // Passa sem o *, porque eu quero passar o endereço do ponteiro,
    // e não o seu valor


    printf("%i \n", teste);
    getchar();
    return 0;
}

void testeVariavel(int x)
{
    // void: não recebe nada
    // recebe como argumento uma variável inteira

    ++x;

}

void testePonteiro(int *pX)
{
    // recebe um ponteiro que contém um endereço de memória
    ++*pX;
}