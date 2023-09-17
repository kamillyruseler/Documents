#include <stdio.h>

int main(void)
{
    struct horario
    {
        int hora;
        int minuto;
        int segundo;
    };

    struct horario agora, *depois; // Declaramos uma estrutura "agora" do tipo horário
    //
    depois = &agora;

    depois -> hora = 20; // Setinha apontando para o membro da estrutura
    depois -> minuto = 80;
    depois -> segundo = 50;

    int somatorio = 100;

    struct horario antes; //Declarar uma estrutura do tipo horário

    antes.hora = somatorio + depois -> segundo; // Soma o valor 100 mais o ponteiro que está apontando em uma estrutura do tipo horário, no membro "segundo", que é 50
    antes.minuto = agora.hora + depois -> minuto;// Agora.hora + depois.minuto
    antes.segundo = depois->minuto + depois->segundo;
    
    printf("%i:%i:%i", antes.hora, antes.minuto, antes.segundo);

    getchar();
    return 0;
}