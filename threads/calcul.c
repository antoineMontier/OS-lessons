#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NB_THREADS 20

void calculate(void);

void calculate(void){
    for(long int i = 0 ; i < 2000000000 ; ++i);
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

    pthread_t tids[NB_THREADS];
    int a, b;
    for(int i = 0; i < NB_THREADS ; i++){
        a = pthread_create(tids + i, NULL, (void *)calculate, NULL);
        if(a == 0)
            printf("thread n°%d opened with sucess\n", i);
        else if(a > 0)
            printf("error in thread n°%d opening with code: %d\n", i, a);
    }


    // =================================== RUNNING ===================================

    for(int i = 0; i < NB_THREADS ; i++){
        b = pthread_join(tids[i], NULL);
        if(b == 0)
            printf("thread n°%d closed with sucess\n", i);
        else if(b > 0)
            printf("error thread n°%d closing with code: %d\n", i, b);
    }

    return 0;
}