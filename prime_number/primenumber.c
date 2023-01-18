#include "primenumber.h"

int fill_tab_of_prime_numbers(unsigned long long int*tab, unsigned long long int size, unsigned long long int max_number){
    unsigned long long int counter = 3;
    unsigned long long int primes_founded = 1;
    unsigned long long int hundred_fraction = max_number / 100;
    char count = 0;
    //each number needs to be check with all the indexes
    while(counter < max_number && tab[size - 1] == 0){
        if(is_prime_for_array(tab, size, counter))
            tab[primes_founded++] = counter;
        counter++;
        /*if(hundred_fraction != 0 && counter % hundred_fraction == 0){
            printf("%d%% = %ld", count++, primes_founded);
            printf("\n");
        }*/
    }
    return primes_founded;
}


