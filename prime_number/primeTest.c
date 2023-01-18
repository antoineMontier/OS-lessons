#include "primeTest.h"

int is_prime_for_array(unsigned long long int*tab, unsigned long long int size, unsigned long long int test_number){
    int i = 0;
    while(tab[i]*tab[i] <= test_number)
        if(test_number % tab[i++] == 0)//check if a number can be divided by any tab coefficient
            return 0;
    return 1;
}