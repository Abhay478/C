
#include <stdio.h>
#include <math.h>

#define T unsigned long long int

int divi(T x)
{
    int count = 0;
    T i;
    for(i = 1; i*i <= x; i++)
        if((x%i) == 0) 
            count++;
    count *= 2;
    //if(i*i == x) count--;
    return count;
}
int main()
{
    //T tr;
    int n;
    for(int i = 1; ; i++){
        n = divi((i*i + i)/2);
        if (n > 300) printf("%d : %d\n", i, n);
        if(n > 500){
            printf("%d\n", (i*i + i)/2);
            break;
        }
    }
        
    
    return 0;
}
