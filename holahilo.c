#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 20

int saldo;

void *printHola(void *arg){
    printf("Hola desde un hilo\n");
    int saldolocal = saldo;

    saldolocal += 100;
    saldo = saldolocal;

    pthread_exit(NULL);
}

int main(){

    pthread_t threads[NUM_THREADS];

    saldo = 0;
    for(int i=0; i<NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, printHola, NULL);
    }

    //sleep(1);

    for(int i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("saldo = %d\n", saldo);
    pthread_exit(NULL);
}

// gcc -o holahilo holahilo.c -lpthread
// ./holahilo
// ./holahilo | wc -l