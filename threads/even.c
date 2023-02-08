#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void even(){
    for(int i = 0; i < 1000 ; i++){
        if(i % 2 == 0)
            printf("even %d\n", i);
        usleep(1);
    }
}

void odd(){
    for(int i = 0; i < 1000 ; i++){
        if(i % 2 == 1)
            printf("odd %d\n", i);
        usleep(1);
    }
}


int main(){ // compile with gcc -pthread even.c -o even
    pthread_t even_t, odd_t;

    pthread_create(&even_t, NULL, (void*)even, NULL);
    pthread_create(&odd_t, NULL, (void*)odd, NULL);

    pthread_join(even_t, NULL);
    pthread_join(odd_t, NULL);
}