
#include <stdio.h>
#include <math.h>

float InvSqrt(float x){
    float xhalf = 0.5f * x;
    int i = *(int*)&x;            // store floating-point bits in integer
    i = 0x5f3759df - (i >> 1);
    printf("%d\n", i);    // initial guess for Newton's method
    x = *(float*)&i;              // convert new bits into float
    printf("%f\n", x);
    x = x*(1.5f - xhalf*x*x);     // One round of Newton's method
    x = x*(1.5f - xhalf*x*x);
    x = x*(1.5f - xhalf*x*x);
    return x;
}



int main()
{
    while(1){
        printf("Enter number.\n");
        float n;
        scanf("%f", &n);
        if(n == -1) return 0;

        printf("%g\n", InvSqrt(n));
        printf("%g\n", 1/sqrt(n));
    }
}