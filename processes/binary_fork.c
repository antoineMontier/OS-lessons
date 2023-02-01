#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void binary_forking_rec(int nb);
void binary_forking_it(int nb);


int main(){//gcc -c binary_fork.c && gcc -o binary_fork binary_fork.o && ./binary_fork


    binary_forking_it(3);
    return 0;
}

void binary_forking_it(int nb){
    printf("Init : <<<%d>>>\n", getpid());
    for(int i=0; i<nb; i++){
        if(fork() && fork()){
            printf("%d >> %d\n", getppid(), getpid());
            wait(NULL);
            wait(NULL);
            exit(0);
        }
    }
}


void binary_forking_rec(int nb){ // the number of processes will be 2^{nb+1} - 1
    if(nb <= 0) return;
    pid_t son1_pid, son2_pid;
    if(      (son1_pid = fork())     &&     (son2_pid = fork())    ){//father
        printf("I'm the father %d, son1 %d,     son2 %d\n", getpid(), son1_pid, son2_pid);
        wait(NULL);
        wait(NULL);
        exit(0);
    }
    binary_forking_rec(nb-1);
}