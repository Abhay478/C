
#include <stdio.h>
#include <math.h>

long int d(long int x)
{
    long int sum = 0;
    for(int i = 1; i < x; i++)
        if(x%i == 0)
            sum += i;
    return sum;
}
int main()
{
    long int sum = 0;
    for(int i = 1; i < 10000; i++)
        if(d(d(i)) == i && d(i) != i)
            sum += i;
    printf("%ld", sum);
    return 0;
}
