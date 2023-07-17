
#include <stdio.h>
#include <stdlib.h>

//prints in non-decreasing order
void print(int * p, int n)
{
    for(int i = n; i >= 0; i--)
       printf("%d ", p[i]);
    printf("\n");
}
 
void Partition(int n)
{
    //p stores a given partition in non-increasing order
    int * p = (int *)calloc(n, sizeof(int)); 
    int a = 0; 
    p[0] = n;

    int diff;

    while(1){
        print(p, a);
        diff = 0;

        for(; a >= 0 && p[a] == 1; a--)
            diff++;
            
        
        if (a < 0){
            free(p);
            return;
        }

        p[a]--;
        diff++;

        for(; diff > p[a]; a++){
            p[a+1] = p[a];
            diff -= p[a];
        }
 
        p[a+1] = diff;
        a++;

        // a is the index of the last non-unit element
    }
    free(p);
}

int main()
{
    int n;
    while (scanf("%d", &n) != -1)
        Partition(n);
    
    return 0;
}