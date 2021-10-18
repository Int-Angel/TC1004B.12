#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 20

int saldo;
pthread_mutex_t lockSaldo = PTHREAD_MUTEX_INITIALIZER;

void *printHola(void *arg){
    printf("Hola desde un hilo\n");
    int saldolocal;

    pthread_mutex_lock(&lockSaldo);

    saldolocal = saldo;
    saldolocal += 100;
    saldo = saldolocal;

    pthread_mutex_unlock(&lockSaldo);

    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];

    saldo = 0;
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i],NULL,printHola,NULL);
    }
    
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i],NULL);
    }
    
    printf("El valor del saldo es %d\n",saldo);

    pthread_exit(NULL);
}

// gcc -o holahilo holahilo.c -lpthread
// ./holahilo
// ./holahilo | wc -l