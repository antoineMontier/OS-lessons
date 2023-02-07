#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>
#define BUFFER_SIZE 1024

int main(int argc, char**argv){

    if(argc == 1){ // no arguments
        printf("Use the compilation program this way : %s source1.c, source2.c...\n", argv[0]);
        return 0;
    }
    char*command = malloc(sizeof(char)*BUFFER_SIZE);

    for(int i=1; i<argc; i++){
        for(int j=0; j<BUFFER_SIZE; j++)
            command[j] = '\0';
        strcat(command, "./comp_easy ");
        strcat(command, argv[i]);
        system(command);
    }

    free(command);

    return 0;
}