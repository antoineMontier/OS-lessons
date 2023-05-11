#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/wait.h>


#define MIN_SIZE    100
#define ARRAY_SIZE  1050

#define THREAD 1
#define FORK 2

typedef struct {
    int* array;
    int start_index;
    int end_index;
    int to_find;
} thread_args;

int* rand_arr(int size);
int search_survenue(int*arr, int arr_size, int to_find, int version);
int linear_search(int*arr, int start, int end, int to_find);
int fork_search(int*arr, int size, int to_find);
void* thread_search(void*);


int main(){
    int* arr = rand_arr(ARRAY_SIZE);

    printf("fork_res = %d\n", search_survenue(arr, ARRAY_SIZE, 16, FORK));
    printf("thread_res = %d\n", search_survenue(arr, ARRAY_SIZE, 16, THREAD));
    printf("linear_res = %d\n", linear_search(arr, 0, ARRAY_SIZE, 16));


    /*
    clock_t start_time, end_time;
    double elapsed_time_ms;


    start_time = clock();
    printf("thread_res = %d\n", search_survenue(arr, ARRAY_SIZE, 16));
    end_time = clock();
    elapsed_time_ms = (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC;
    printf("Elapsed time: %f ms\n", elapsed_time_ms);

    start_time = clock();
    printf("linear_res = %d\n", linear_search(arr, 0, ARRAY_SIZE, 16));
    end_time = clock();
    elapsed_time_ms = (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC;
    printf("Elapsed time: %f ms\n", elapsed_time_ms);
    */
    return 0;
}


int linear_search(int*arr, int start, int end, int to_find){
    int nb = 0;
    for(int i=start; i<end; ++i) if(arr[i] == to_find){
        printf("%d found on slot %d\n", to_find, i);
        ++nb;
    }
    return nb;
}


int search_survenue(int*arr, int arr_size, int to_find, int version){
    if(MIN_SIZE < 2){
        printf("MIN_SIZE must be at least 2\n");
        return -1;
    } if(version == THREAD){
        pthread_t launcher;
        thread_args args = {arr, 0, arr_size, to_find};
        pthread_create(&launcher, NULL, (void*)thread_search, (void*)(&args));
        int*res;
        pthread_join(launcher, (void**)&res);
        int return_value = *res;
        free(res);
        return return_value;
    } else if(version == FORK){
        return fork_search(arr, arr_size, to_find);
    }else{
        printf("Version must be THREAD or FORK\n");
        return -1;
    }
}

int fork_search(int*arr, int size, int to_find){
    if(size <= MIN_SIZE) return linear_search(arr, 0, size, to_find);
    pid_t father = getpid();
    int nb_forks = size/MIN_SIZE;
    pid_t sons[nb_forks]; // store the sons
    for(int i = 0; i < nb_forks; i++) sons[i] = 0; // initialize
    int personal_count;
    for(int i = 0; getpid() == father && i < nb_forks ; ++i){
        sons[i] = fork();
        if(sons[i] == 0){ // son process
            // printf("\tlaunching between %d and %d\n", i*MIN_SIZE, (i+1)*MIN_SIZE);
            personal_count = linear_search(arr, i*MIN_SIZE, (i+1)*MIN_SIZE, to_find);
        }
    }
    // father will read the remaining slots :
    int count;
    if(getpid() == father){
        // printf("\tfather launching between %d and %d\n", size - (size % MIN_SIZE), size);
        count = linear_search(arr, size - (size % MIN_SIZE), size, to_find);
    }
    // join
    for(int i = 0 ; i < nb_forks ; ++i){
        if(getpid() == father){
            int tmp;
            wait(&tmp);
            count += WEXITSTATUS(tmp);
        }else
            exit(personal_count);
    }
    return count;
}


int* rand_arr(int size){
    srand(time(NULL));
    int*res = malloc(size*sizeof(int));
    for(int i=0; i<size; i++)
        res[i] = rand() % 100;
    return res;
}

void* thread_search(void* t_args){
    thread_args* args = (thread_args*)t_args;
    int size = args->end_index - args->start_index;
    // if array is less than MIN_SIZE, use a linear search and return the result
    if(size < MIN_SIZE){
        int* res = malloc(sizeof(int));
        *res = linear_search(args->array, args->start_index, args->end_index, args->to_find);
        pthread_exit((void*)res);
    }else{
        // array is more than MIN_SIZE, launch two threads
        pthread_t th1, th2;
        int middle = (args->start_index + args->end_index)/2;
        thread_args arg1 = {args->array, args->start_index, middle, args->to_find};
        thread_args arg2 = {args->array, middle, args->end_index, args->to_find};
        pthread_create(&th1, NULL, (void*)thread_search, (void*)(&arg1));
        pthread_create(&th2, NULL, (void*)thread_search, (void*)(&arg2));
        int *ans1, *ans2;
        pthread_join(th1, (void **)&ans1);
        pthread_join(th2, (void **)&ans2);
        // return ans1 + ans2
        int* res = malloc(sizeof(int));
        *res = *ans1 + *ans2;
        free(ans2); free(ans1);
        pthread_exit((void*)res);
    }
}