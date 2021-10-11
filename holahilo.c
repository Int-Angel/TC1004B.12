#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 20

void *printHola(void *arg){
    printf("Hola desde un hilo\n");
    pthread_exit(NULL);
}

int main(){

    pthread_t threads[NUM_THREADS];

    for(int i=0; i<NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, printHola, NULL);
    }

    pthread_exit(NULL);
}

// gcc -o holahilo holahilo.c -lpthread
// ./holahilo
// ./holahilo | wc -l