#include <stdio.h>
#include <unistd.h>

int main(){

        int pid = fork();
        if(pid == 0 ){
            printf("soy el proceso hijo\n");
        }else{
            printf("soy el proceso padre y mi hijo es %d\n",pid);
        }

    return 0;
}