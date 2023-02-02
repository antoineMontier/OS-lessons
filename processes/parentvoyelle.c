#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char **argv){
    if(argc == 1)
        return 0;
    for(int i=1; i<argc; i++){
        if(fork() == 0){
            execl("/home/antoine/Prog/c/Cours/processes/mainvoyelle", "/home/antoine/Prog/c/Cours/processes/mainvoyelle", argv[i], NULL);
            int n=-1;
            wait(&n);
            n = WEXITSTATUS(n);
            exit(n);
        }else{
            int n;
            wait(&n);
            n = WEXITSTATUS(n);
            printf("In %s file, the most used voeylle is : %c\n", argv[i], n);
        }
    }
    
}