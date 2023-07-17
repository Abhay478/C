
#include <stdio.h>
#include <math.h>

#define T unsigned long long int

int collatz(T x)
{
    int count = 1;
    while(x > 1){
        if(x%2) x = 3*x + 1;
        else x /= 2;

        count++;
    }
    return count;
}
int main()
{
    int col, n = 1;
    for(int i = 1; i < 1000000; i++){
        if(collatz(i) > n){
            col = i;
            n = collatz(i);
        }
    }

    printf("%d\n", col);
}