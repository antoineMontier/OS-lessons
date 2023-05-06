#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void linear_fork(int nb_process);
void binary_fork(int nb_process);

int main(){
    binary_fork(3);
    return 0;
}


void linear_fork(int nb_process){
    if(nb_process <= 0) return;
    pid_t son_pid = fork();

    if(son_pid == 0){
        printf("Iteration %d\tI'm %d, son of %d\n", nb_process, getpid(), getppid());
        linear_fork(nb_process - 1);
        wait(NULL);
        exit(0);
    }
}

void binary_fork(int nb_process){
    printf("%d\tactual %d\tfather %d\n", nb_process, getpid(), getppid());
    if(nb_process <= 0) exit(0);
    if(fork() && fork()){
        wait(NULL);
        wait(NULL);
        exit(0);
    }
    binary_fork(nb_process-1);
}
