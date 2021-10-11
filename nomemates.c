#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle(int signal){
    printf("Jajajaj %d\n", signal);
}

int main(){

    signal(2, handle);

    while(1){
        printf("Trabando\n");
        sleep(1);
    }

    return 0;
}