#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void binary_forking(int nb);

int main(){//gcc -c binary_fork.c && gcc -o binary_fork binary_fork.o && ./binary_fork


    binary_forking(3);
    return 0;
}

void binary_forking(int nb){
    if(nb <= 0) return;
    pid_t son1_pid = fork();
    pid_t son2_pid;
    
    if(son1_pid > 0){//father
        son2_pid = fork();
        if(son2_pid > 0){//father
            printf("I'm the father %d, son1 %d,     son2 %d\n", getpid(), son1_pid, son2_pid);
            wait(NULL);
            wait(NULL);
            exit(0);
        }
    }

    binary_forking(nb-1);

}