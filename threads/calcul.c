#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void calculate(void);

void calculate(void){
    int k;
    do{k = rand();}while(k != RAND_MAX-1);
    //pthread_exit(NULL);
    /*
    One call : 

    real	0m8,589s // time between the start and end
    user	0m8,580s // time took by the process to execute
    sys	    0m0,008s // time took by the system access functions (fork, FILE*..)


    Two calls :

    real	0m14,546s
    user	0m14,544s
    sys	    0m0,001s
    */
}

int main(){ // compile with gcc -pthread calcul.c -o calcul

    pthread_t tid;
    int a = pthread_create(&tid, NULL, (void *)calculate, NULL);
    if(a == 0)
        printf("sucess\n");
    else if(a > 0)
        printf("error with code: %d\n", a);
        
    return 0;
}