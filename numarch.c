#include <unistd.h>
#include <stdio.h>


int main(){
    int fd[2];
    pipe(fd);
    int pid = fork();

    if(pid == 0){
        // proceso hijo
        //close(0);

        close(0);
        dup(fd[0]);
        close(fd[1]);
        execlp("wc","wc","-l",NULL);
    }else{
        // proceso padre
        //close(1); // 1-> es la salida estandar, 0 -> es la entrada estandar

        close(1);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls","ls",NULL);
    }

    return 0;
}