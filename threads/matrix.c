#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TAILLE 10000
#define NB_THREAD 8

int **mat;

void count(int col){
    int* res = malloc(sizeof(int));
    *res = 0;
    for(int i=0; i<TAILLE; i++)
        if(mat[col][i] == 0)
            (*res)++;
    printf("col = %d, res = %d\n", col, *res);
    pthread_exit((void *)res);
}

int main(){

    srand(1);
    mat=(int**) malloc (sizeof(int*)*TAILLE);
    for(int i=0;i<TAILLE;++i)
        mat[i] = (int*)malloc(sizeof(int)*TAILLE);

    for (int i=0;i<TAILLE; ++i)
        for (int j=0; j<TAILLE; ++j) 
            mat[i][j] = rand() % 5;

    int total_z = 0;


    int i = 0, nb_tests;
    pthread_t tids[NB_THREAD];

    while(i < TAILLE){
        if(i > TAILLE - NB_THREAD)
            nb_tests = TAILLE - i;
        else 
            nb_tests = NB_THREAD;

        int a, b;
        for(int j = i; j < nb_tests ; j++){
            int col_now = j;
            a = pthread_create(tids + i, NULL, (void *)count, &col_now);
        }


        // =================================== RUNNING =================================

        printf("before cuting threads\n");
        for(int j = i; j < nb_tests ; j++){
            int *p;
            b = pthread_join(tids[j], (void **)&p);
            printf("j=%d b=%d \n*p=%d\n", j, b, *p);
            total_z += *p;
            free(p);
        }
        printf("i = %d\n", i);
    }

    printf("final value: %d\n", total_z); // finale value is not 2*BILION because the thread are working simultaneously

    return 0;

}