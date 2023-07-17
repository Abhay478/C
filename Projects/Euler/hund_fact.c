
#include <stdio.h>
#include <math.h>

#define L long double
int main()
{
    L fact = 1;
    for(int i = 1; i < 100; i++){
        fact *= i;
        fact /= 10;
    }
    
    printf("%Lf\n", fact*pow(10, 100));
    return 0;
}