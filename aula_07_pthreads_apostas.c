#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

int numero;
int ganhadora = -1;
int num_tentativas;
int sorteado = 0;

pthread_cond_t cv_numero_sorteado = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_contador = PTHREAD_MUTEX_INITIALIZER;

int gerarNumeroAleatorio() {
    return rand() % 100 + 1;
}

void *auditora(void *thread_id) {
    pthread_mutex_lock(&mutex_contador);
    while (!sorteado) {
        pthread_cond_wait(&cv_numero_sorteado, &mutex_contador);
    }
    printf("Número sorteado: %d\n", numero);
    pthread_mutex_unlock(&mutex_contador);

    return NULL;
}

void *apostadora(void *thread_id) {
    int tid = *(int *)thread_id;
    int numero_apostado;
    int numero_tentativas = 0;

    while (!sorteado) {
        pthread_mutex_lock(&mutex_contador);
        numero_apostado = gerarNumeroAleatorio();
        numero_tentativas++;
        printf("Apostador %d, Tentativa %d, Número apostado: %d\n", tid, numero_tentativas, numero_apostado);

        if (numero_apostado == numero) {
            ganhadora = tid;
            num_tentativas = numero_tentativas;
            sorteado = 1;

            printf("Apostador %d acertou o número em %d tentativas. Número apostado: %d\n", tid, num_tentativas, numero_apostado);

            // Sinaliza a todos que o número foi acertado
            pthread_cond_broadcast(&cv_numero_sorteado);
            pthread_mutex_unlock(&mutex_contador);
            break;
        }

        pthread_mutex_unlock(&mutex_contador);
        usleep(500000);  // Simula a aposta em intervalos de 0,5 segundos
    }

    return NULL;
}

int main() {
    srand(time(NULL));
    numero = gerarNumeroAleatorio();

    printf("Número sorteado: %d\n", numero);

    pthread_t threads[5];
    int thread_ids[4];  // Apenas 4 apostadoras

    for (int i = 0; i < 4; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, apostadora, (void *)&thread_ids[i]);
    }

    pthread_create(&threads[4], NULL, auditora, NULL);

    // Aguarda a auditora terminar
    pthread_join(threads[4], NULL);

    // Aguarda as apostadoras terminarem
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
