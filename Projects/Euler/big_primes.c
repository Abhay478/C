
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool Prime(int n)
{
    if(n == 3 || n == 2) return true;
    if(n <= 1 || n%3 == 0 || n%2 == 0) return false;
    double x = sqrt(n);
    for(int i = 5; i <= x; i += 6)
        if(n%i == 0 || n%(i + 2) == 0) return false;

    return true;
}

int getprime(int n)
{
    for(int i = n + 1; ; i++)
        if(Prime(i)) return i;
}

int primesum()
{
    int sum = 0;
    int p = 1;
    int m = 0;
    int count = 0;
    int mcount = 0;
    while(1){
        p = getprime(p);
        if(p + sum > 100) break;
        sum += p;
        count++;
        if(Prime(sum)){
            m = sum;
            mcount = count;
        }
    }
    p = 1;
    while(!Prime(sum)){
        p = getprime(p);
        sum -= p;
    }

    return sum;
}

int main()
{
    printf("%d\n", primesum());
    return 0;
}