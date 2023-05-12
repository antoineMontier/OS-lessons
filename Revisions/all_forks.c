#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void linear_fork(int nb_process);
void binary_fork(int nb_process);

int main(){
    linear_fork(3);
    return 0;
}


void linear_fork(int nb_process){
    if(nb_process <= 0) exit(0);
    if((fork()) == 0){
        printf("Iteration %d\tI'm %d, son of %d\n", nb_process, getpid(), getppid());
        linear_fork(nb_process - 1);
        exit(0);
    }else
        wait(NULL);
}

void binary_fork(int nb_process){
    if(nb_process <= 0) exit(0);
    pid_t s1, s2;
    if((s1 = fork()) && (s2 = fork())){
        printf("%d\tactual: %d\tfather: %d\n\t\ts1: %d\ts2: %d\n", nb_process, getpid(), getppid(), s1, s2);
        wait(NULL);
        wait(NULL);
        exit(0);
    }
    binary_fork(nb_process-1);
}
