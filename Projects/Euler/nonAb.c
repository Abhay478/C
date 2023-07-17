
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


bool abun(int n)
{
    int sum = 0;
    for(int i = 1; i < n; i++)
        sum += (n%i == 0)? i : 0;
    return (sum > n)? true : false;
}

int main()
{
    //short int * abs = (short int *)calloc(1, sizeof(short int));
    //short int count = 0;
    long int sum = 0;
    bool flag = 0;
    for(int i = 1; i < 28123; i++){
        for(int j = 1; j <= i/2; j++){
            if(abun(j) && abun(i - j)){
                flag = 1;
                break;
            }
        }
        if(flag == 0) sum += i;
    }
    //printf("%d\n", count);
    
    

    printf("%ld\n", sum);    
    return 0;
}

