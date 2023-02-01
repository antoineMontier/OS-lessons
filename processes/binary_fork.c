#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void binary_forking_rec(int nb, int*nb_process);
void binary_forking_it(int nb);


int main(){//gcc -c binary_fork.c && gcc -o binary_fork binary_fork.o && ./binary_fork

    int n = 0;
    binary_forking_rec(3, &n);

    printf("%d\n", n);
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


void binary_forking_rec(int nb, int*nb_process){ // the number of processes will be 2^{nb+1} - 1
    if(nb <= 0) exit(1); // leaf    
    pid_t son1_pid, son2_pid;
    if(      (son1_pid = fork())     &&     (son2_pid = fork())    ){//father
        //printf("I'm the father %d, son1 %d,     son2 %d\n", getpid(), son1_pid, son2_pid);

        int n, m;
        wait(&n);
        n = WEXITSTATUS(n);
        wait(&m);
        m = WEXITSTATUS(m);
        *nb_process = n+m;
        printf("%d\n", n+m);
        exit(n+m);
    }
    binary_forking_rec(nb-1, nb_process);
}