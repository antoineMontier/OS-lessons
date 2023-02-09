#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BILION 10000000
#define NB_THREAD 2

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int x;

void incrementation(){
    for(int i=0; i<BILION; i++){// let's add a static mutex to avoid two incrementations at the same time

        pthread_mutex_lock(&mutex);
        x = x + 1;
        pthread_mutex_unlock(&mutex);

    }
    pthread_exit(NULL);
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

    printf("final value: %d\n", x); // finale value is not 2*BILION because the thread are working simultaneously

    return 0;
}