
#include <stdio.h>
#include <math.h>

#define T unsigned long long int
int prime(int x)
{
    for(int i = 2; i <= sqrt(x); i++){
        if(!(x%i))
            return 0;
    }
    return 1;
}
int main()
{
    T pr = 0;
    for(int i = 2; i <2000000; i++)
        if(prime(i) == 1) pr += i;
    printf("%llu", pr);
    return 0;
}
