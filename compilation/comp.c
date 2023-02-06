#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char**argv){

    if(argc == 1){ // no arguments
        printf("Use the compilation program this way : %s source1.c, source2.c...\n", argv[0]);
        return 0;
    }

    for(int i=1; i<argc; i++){
        if(!fork()){
            char *args[] = {"./comp_easy", argv[i], NULL};
            char *environ[] = { NULL };
            execve("./comp_easy", args, environ);
        }
    }

    for(int i=1; i<argc; i++){
        wait(NULL);
    }
    

    return 0;
}