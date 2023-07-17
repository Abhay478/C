
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define T unsigned long long int

bool isPrime(T num)
{
    for(T i = 2; i <= sqrt(num); i++)
        if(!(num%i))
            return 0;
    return 1;
}

void print_factors(T num)
{
    if(isPrime(num))
        printf("Number is prime. No factors.");
    else
        T k, i = 2;
        printf("Factors of the given number are : \n");
        for(i = 2; i<=sqrt(num); i++){
            if(!(y%i)){
                printf("%ld\n%ld\n", i, y/i);
                k++;
            }
        }
        printf("A total of %d factors. \n", k);
}