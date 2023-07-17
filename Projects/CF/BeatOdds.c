
#include <stdio.h>
#include <stdlib.h>

int Check(int * a, int n)
{
    static int count = 0;
    if(n == 1)
        return count;
    
    if(n == 2){
        if((a[0] + a[1])%2)
            count++;
        
        return count;
    
    }

    if((a[0] + a[1])%2){
        if((a[2] + a[1])%2){
            count++;
        }
        if((a[2] + a[0])%2){
            count++;
        }
    }
    Check(a + 2, n - 2);
    return count;
    
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    
    int n;
    int * a;

    for(int q = 0; q < N; q++){
        scanf("%d", &n);
        a = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        
        printf("%d\n", Check(a, n));
        free(a);
    }
    
    return 0;
}