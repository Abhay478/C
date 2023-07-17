
#include <stdio.h>
#include <stdlib.h>

unsigned long int power(int m, int k)
{
    unsigned long int run = m;
    unsigned long int out = 1;
    int exp = 1;
    if(k == 0) return 1;
    if(m == 1) return 1;
    if(k == 1) return m;

    while(k != 0){
        for(; 2*exp <= k; exp *= 2)
            run *= run;
        
        out *= run;
        run = m;
        k -= exp;
        exp = 1;
    }
    
    return out;
    
}

int main()
{
    int m = 0, k = 0;
    while(scanf("%d", &m) != -1 && scanf("%d", &k) != -1)
        printf("%lu\n", power(m, k));

    return 0;
}