
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K unsigned int
K setpos(K x, K p, K n, K y)
{
    //set up y for ANDing
    y &= (K)(pow(2, n) - 1);
    y |= (~(K)(pow(2, n) - 1));
    y <<= (p+1 - n);
    y |= ((K)(pow(2, p+1 - n) - 1));
    //set up mask for resetting bits of x to be changed
    K mask = ~((K)(pow(2, n) - 1) << (p+1 - n));
    //actual change
    x &= mask;
    x &= y;
    
    return x;
    
}

K rightrot(K x, K n)
{
    K last_bit;
    for(int i = 1; i <= n; i++){
        last_bit = 1;
        last_bit &= x;
        last_bit <<= 31;
        x >>= 1;
        x |= last_bit;
    }
    return x;
}

K invert(K x, K p, K n)
{
    K mask = ((K)(pow(2, n) - 1)<<(p+1 - n));
    x ^= mask;
    return x;
}

int main()
{
    printf("Enter x.");
    K x0;
    scanf("%u", &x0);

    //printf("Enter y.");
    //K y0;
    //scanf("%u", &y0);

    //printf("Enter p.");
    //K p0;
    //scanf("%u", &p0);

    printf("Enter n.");
    K n0;
    scanf("%u", &n0);

    //K shifted = setpos(x0, p0, n0, y0);

    //K inv = invert(x0, p0, n0);

    K rot = rightrot(x0, n0);
    printf("%u", rot);
}