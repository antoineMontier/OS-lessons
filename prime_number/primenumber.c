#include <stdlib.h>
#include <stdio.h>

#ifndef NUMBER
    #define NUMBER 10000000//gcc -D NUMBER=<number>
#endif

#define PRIME_MAX 700000

void fill_tab_of_prime_numbers(unsigned long long int*tab, unsigned long long int size, unsigned long long int max_number);

int is_prime_for_array(unsigned long long int*tab, unsigned long long int size, unsigned long long int test_number);

// the goal is to create an algorithm to know how many prime numbers are before the NUMBER
int main(){//10 000 000 : 664579
    unsigned long long int *tab = malloc(PRIME_MAX * sizeof(unsigned long long int));//give memory for the algo
    //initialize the tab
    for(int i = 0 ; i < PRIME_MAX ; i++)
        tab[i] = 0;
    tab[0] = 2; // first prime number

    unsigned long long int r = 0;
    fill_tab_of_prime_numbers(tab, PRIME_MAX, NUMBER);

    while(tab[r++] != 0);

    printf("%d\n", r);

    //for(int i = 0; i < 15; i++)
    //    printf("%d ", tab[i]);
    printf("\n");
    free(tab);//free memory
    return 0;
}

void fill_tab_of_prime_numbers(unsigned long long int*tab, unsigned long long int size, unsigned long long int max_number){
    unsigned long long int counter = 3;
    unsigned long long int primes_founded = 1;
    unsigned long long int hundred_fraction = max_number / 100;
    char count = 0;
    //each number needs to be check with all the indexes
    while(counter < max_number && tab[size - 1] == 0){
        if(is_prime_for_array(tab, size, counter))
            tab[primes_founded++] = counter;
        counter++;
        //if(hundred_fraction != 0 && counter % hundred_fraction == 0){
        //    printf("%d%% = %ld", count++, primes_founded);
        //    printf("\n");
        //}
    }
}


int is_prime_for_array(unsigned long long int*tab, unsigned long long int size, unsigned long long int test_number){
    int i = 0;
    while(tab[i]*tab[i] <= test_number)
        if(test_number % tab[i++] == 0)//check if a number can be divided by any tab coefficient
            return 0;
    return 1;
}