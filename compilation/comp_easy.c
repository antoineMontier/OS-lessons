#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "Error in comp_easy.c, provide 2 arguments\n");
        return 1;
    }if(!(strlen(argv[1]) > 2 && argv[1][strlen(argv[1])-1] == 'c')){
        fprintf(stderr, "error, the file to compile must be a .c file\n");
        return 1;
    }
    char* command = malloc(256);
    command[0] = 'g';
    command[1] = 'c';
    command[2] = 'c';
    command[3] = ' ';
    strcat(command, argv[1]);
    strcat(command, " > log.txt");



    printf("%s\n", command);
    system(command);
    
}