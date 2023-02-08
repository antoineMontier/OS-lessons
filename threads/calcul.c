#include <stdio.h>
#include <stdlib.h>

void calculate(){
    int k;
    do{k = rand();}while(k != RAND_MAX-1);
}

int main(){
    calculate();
    return 0;
}