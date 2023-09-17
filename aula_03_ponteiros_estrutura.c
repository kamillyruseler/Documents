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

    //*depois.hora = 20; // Isso dá erro, porque há uma precedência de sinais
    // o ponto no C é considerado primeiro em execução, do que o *
    // ou seja, o que ele está fazendo é (depois.hora)*
    // ao invés de (*depois).hora
    // analogia: pense na matemática, em operações de multiplicação e soma, por ex.
    // Uma forma de fazer dar certo seria assim:
    /*
        (*depois).hora = 20;
        (*depois).minuto = 20;
        (*depois).segundo = 20; */

    // Mas eles fizeram uma forma mais legível de fazer isso:

    depois -> hora = 20; // Setinha apontando para o membro da estrutura
    depois -> minuto = 20;
    depois -> segundo = 20;

    printf("%i:%i:%i", agora.hora, agora.minuto, agora.segundo);

    getchar();
    return 0;
}