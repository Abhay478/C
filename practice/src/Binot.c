
#include <stdio.h>
#include <math.h>
#define PHI (sqrt(5) + 1)/2
int main()
{
    printf("Enter length of list.");
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        printf("fib[%d] = %g\n", i + 1, (pow(PHI, i) - pow(PHI - sqrt(5.0), i))/sqrt(5.0));
    }
    return 0;
    
}