#include "primenumber.h"

#ifndef NUMBER
    #define NUMBER 10000000//gcc -D NUMBER=<number>
#endif

#define PRIME_MAX 700000

int main(){//10 000 000 : 664579
    unsigned long long int *tab = malloc(PRIME_MAX * sizeof(unsigned long long int));//give memory for the algo
    for(int i = 0 ; i < PRIME_MAX ; i++)
        tab[i] = 0;
    tab[0] = 2;


    printf("%d\n", fill_tab_of_prime_numbers(tab, PRIME_MAX, NUMBER));


    free(tab);
    return 0;
}