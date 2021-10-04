#include <unistd.h>
#include <stdio.h>


int main(){
    int fd[2];
    pipe(fd);
    int pid = fork();

    if(pid == 0){
        // proceso hijo
        //close(0);

        dup2(0, fd[0]);
        execlp("wc","wc","-l", NULL);
    }else{
        // proceso padre
        //close(1); // 1-> es la salida estandar, 0 -> es la entrada estandar

        dup2(1, fd[1]);
        execlp("ls", "ls", NULL);
    }

    return 0;
}