#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

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

    pthread_t tid1, tid2;
    int a, b;
    // -- launch first thread --
    a = pthread_create(&tid1, NULL, (void *)calculate, NULL);
    if(a == 0)
        printf("thread opened with sucess\n");
    else if(a > 0)
        printf("error opening with code: %d\n", a);

    // -- launch second thread --
    a = pthread_create(&tid2, NULL, (void *)calculate, NULL);
    if(a == 0)
        printf("thread opened with sucess\n");
    else if(a > 0)
        printf("error opening with code: %d\n", a);

    // =================================== RUNNING =================================

    // -- end first thread --
    b = pthread_join(tid1, NULL);
    if(b == 0)
        printf("thread closed with sucess\n");
    else if(b > 0)
        printf("error closing with code: %d\n", b);

    // -- end second thread --
    b = pthread_join(tid2, NULL);
    if(b == 0)
        printf("thread closed with sucess\n");
    else if(b > 0)
        printf("error closing with code: %d\n", b);

    return 0;
}