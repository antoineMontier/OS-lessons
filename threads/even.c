#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int i;


void even(){
    int last;
    while(i < 1000){
        if(last != i && !(i % 2)){
            printf("even %d\n", i);
            last = i;
        }
    }    
    pthread_exit(NULL);
}

void odd(){
    int last;
    while(i < 1000){
        if(last != i && (i % 2)){
            printf("odd %d\n", i);
            last = i;
        }
    }
    pthread_exit(NULL);
}

int main(){ // compile with gcc -pthread even.c -o even
    pthread_t even_t, odd_t;

    pthread_create(&even_t, NULL, (void*)even, NULL);
    pthread_create(&odd_t, NULL, (void*)odd, NULL);


    for(i = 0 ; i < 1000 ; i++){usleep(1);}


    pthread_join(even_t, NULL);
    pthread_join(odd_t, NULL);
}