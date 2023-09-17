#include <stdio.h>

int main(void) {

    int x; // Fomos na memória do PC e dissemos que
    // precisamos de um espaço para armazenar um valor inteiro
    x = 10;              // Naquele espaço, quero jogar o valor 10
    printf("%i \n", x);  // Printa o valor de x
    printf("%i \n", &x); // Acessa o endereço

    int *ponteiro; // Preciso dizer qual o tipo de dado o meu ponteiro estará apontando
    ponteiro = &x; // Endereço de memória da minha variável x
    printf("%i \n", *ponteiro); // Se eu não colocar o *, estaria acessando o endereço de memória
    // Quando eu passo o *, eu acesso o valor daquela memória

    getchar();
    return 0;
}