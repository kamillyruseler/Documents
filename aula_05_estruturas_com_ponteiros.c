#include <stdio.h>

int main (void){

    struct horario{
        int *pHora;
        int *pMinuto;
        int *pSegundo;
    };

    struct horario hoje;

    int hora = 200;
    int minuto = 300;
    int segundo = 400;
    

    hoje.pHora = &hora; // Esse ponteiro vai apontar para
    // o endereço de memória de hora
    hoje.pMinuto = &minuto;
    hoje.pSegundo = &segundo;

    printf("Hora - %i \n", *hoje.pHora);
    printf("Minuto - %i \n", *hoje.pMinuto);
    printf("Segundo - %i \n", *hoje.pSegundo);

    *hoje.pSegundo = 1000; // Quando eu escrevo o *,
    // significa que estou alterando o valor
    printf("Segundo alterado - %i \n", *hoje.pSegundo);



    getchar();
    return 0;

}