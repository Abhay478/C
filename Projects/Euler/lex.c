
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

bool reps(long int n)
{
    for(; n > 0; n /= 10)
        if(n%10 == (n%100)/10) return true;
    
    return false;
}

int main()
{
    int n = 0;
    char s[11];
    for(long int i = 123456789, count = 0; count <= 1000000; i++){
        sprintf(s, "%d", i)
        if(!reps())
    }
    printf("%d\n", n);
}