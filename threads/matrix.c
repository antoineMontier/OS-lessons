#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TAILLE 10000
#define NB_THREAD 8

int **mat;

void count(void* col){
    //printf("starting count with col=%d\n", (int)col);
    int* res = malloc(sizeof(int));
    *res = 0;
    if((int)col >= TAILLE) pthread_exit((void *)res);
    //printf("malloc ok\n");
    for(int i=0; i<TAILLE; i++)
        if(mat[(int)col][i] == 0)
            (*res)++;
    //printf("finished count\n");
    //printf("col = %d, res = %d\n", (int)col, *res);
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

    int *total_z = malloc(sizeof(int));
    *total_z = 0;

    int nb_tests;
    pthread_t tids[NB_THREAD];

    for(int i = 0 ; i < TAILLE ; i+=6){

        int a, b;
        for(int j = 0; j < 6 ; j++){
            int col_now = j;
            //printf("giving a thread the col value of %d\n", col_now);
            a = pthread_create(tids + j, NULL, (void *)count, (void*)col_now);
            if (a != 0) {
                printf("Error creating thread\n");
                exit(1);
            }
        }


        // =================================== RUNNING ===================================


        //printf("before cuting threads\n");
        for(int j = 0; j < 6 ; j++){
            int *p;
            b = pthread_join(tids[j], (void **)&p);
            if(b > 0){
                printf("error at closing thread n°%d - code: %d\n", i, b);
                free(p);
                exit(1);
            }
            *total_z = *total_z + *p;
            free(p);
        }
        //printf("i = %d \t%d\n", i, *total_z);
    }

    printf("final value: %d\n", *total_z);
    free(total_z);
    return 0;

}