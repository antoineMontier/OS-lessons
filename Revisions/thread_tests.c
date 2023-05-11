#include <pthread.h>
#include <stdio.h>

typedef struct {
    char * title;
    double coefficient;
} my_args;

void thread_function(void* arg);

int main(){
    my_args thread_args = {"basic title", -3.6};
    pthread_t id;
    if(pthread_create(&id, NULL, (void*)thread_function, (void*)&thread_args) == 0) printf("thread launch succeeded\n"); 
    else printf("thread launch failed\n");

    my_args * result;
    if(pthread_join(id, (void**)&result) == 0) printf("thread closed with sucess\n");
    else printf("thread closing failed\n");
    result = (my_args*)result; // cast
    printf("title = %s coefficient = %f\n", result->title, result->coefficient); // prints the modified value of the coefficient
    return 0;
}

void thread_function(void* arg){
    my_args * args = (my_args*)arg; // cast from void* to my_args* type
    // === display
    printf("Thread: title = \"%s\" coefficient = %f\n", args->title, args->coefficient); // prints the original value of the coefficient
    // === modify content
    args->coefficient *= 0.1; 
    pthread_exit((void*)args);
}