#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char **argv){
    if(argc == 1)
        return 0;
    for(int i=1; i<argc; i++){
        const char * argument = argv[i];
        if(fork() == 0)
            execl("/home/antoine/Prog/c/Cours/processes", "mainvoyelle", argument, NULL);
        else{
            int n;
            wait(&n);
            n = WEXITSTATUS(n);
            printf("In %s file, the most used voeylle is : %c\n", argv[i], n);
        }
    }
    
}