#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MILION 1000000
#define NB_THREAD 2

int x;

void incrementation(){
    for(int i=0; i<MILION; i++)
        x++;
}

int main(){

    pthread_t tids[NB_THREAD];
    int a, b;
    for(int i = 0; i < NB_THREAD ; i++){
        a = pthread_create(tids + i, NULL, (void *)incrementation, NULL);
        if(a == 0)
            printf("thread n°%d opened with sucess\n", i);
        else if(a > 0)
            printf("error in thread n°%d opening with code: %d\n", i, a);
    }


    // =================================== RUNNING =================================

    for(int i = 0; i < NB_THREAD ; i++){
        b = pthread_join(tids[i], NULL);
        if(b == 0)
            printf("thread n°%d closed with sucess\n", i);
        else if(b > 0)
            printf("error thread n°%d closing with code: %d\n", i, b);
    }

    printf("final value: %d\n", x);

    return 0;
}