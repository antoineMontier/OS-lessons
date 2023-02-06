#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>
#define BUFFER_SIZE 256

void check_logs();

int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "Error in comp_easy.c, provide 2 arguments\n");
        return 1;
    }if(!(strlen(argv[1]) > 2 && argv[1][strlen(argv[1])-1] == 'c')){
        fprintf(stderr, "error, the file to compile must be a .c file\n");
        return 1;
    }
    char* command = malloc(BUFFER_SIZE*sizeof(char));
    command[0] = 'g';
    command[1] = 'c';
    command[2] = 'c';
    command[3] = ' ';
    command[4] = '-';
    command[5] = 'c';
    command[6] = ' ';    strcat(command, argv[1]);
    strcat(command, " > log.txt");



    printf("%s\n", command);
    system(command);
    // check the object result

    check_logs();




    //let's do the second command (-o)
    for(int i=0; i<BUFFER_SIZE; i++){
        command[i] = '\0';
    }
    command[0] = 'g';
    command[1] = 'c';
    command[2] = 'c';
    command[3] = ' ';
    command[4] = '-';
    command[5] = 'o';
    command[6] = ' ';
    strcat(command, argv[1]);
    command[strlen(command)-1] = '\0'; // remove '.'
    command[strlen(command)-1] = '\0'; // remove 'c'
    printf("%s\n", command);

    command[strlen(command)] = ' ';
    strcat(command, argv[1]); 
    command[strlen(command) - 1] = 'o'; // specify the o file
    strcat(command, " > log.txt");

    //run the command
    printf("%s\n", command);

    system(command);

    check_logs();

    free(command);
    return 0;

    
}


void check_logs(){
    FILE *f = fopen("log.txt", "r");
    if(f == NULL){
        fprintf(stderr, "error running the compilation command\n");
        fclose(f);
        exit(-1);
    }

    if(fgetc(f) != -1){
        fprintf(stderr, "error in the return value of the compilation command, check log.txt\n");
        fclose(f);
        exit(-1);
    }

    printf("command suceeded\n");
    fclose(f);
}
