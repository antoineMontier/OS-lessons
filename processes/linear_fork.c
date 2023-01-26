#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void forking(int nb);

int main(){

    forking(4);
    return 0;
}

void forking(int nb){
    if(nb <= 0) return;
    pid_t son_pid = fork();
    if(son_pid == 0){
        printf("I'm the child of %d ; my pid is %d\n", getppid(), getpid());
        forking(nb-1);
        wait(NULL);
        exit(0);
    }
}