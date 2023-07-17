
#include <stdio.h>
#include <math.h>

int main()
{
    double c;
    for(int a = 1; a <= 1000; a++)
        for(int b = a + 1; b <= 1000; b++)
            if((c = sqrt(a*a + b*b)) + a + b == 1000){
                printf("%g\n", c*a*b );
                printf("%d\t%d", a, b);
            }
                
        
    return 0;
}