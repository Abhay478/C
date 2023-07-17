
#include <stdio.h>
#include <stdlib.h>

void runs(int * a, int n)
{
    for(int i = 1; i < n; i++)
        if(a[i] > 0 && a[i - 1] > 0) {printf("NO.\n"); return;}
    
    for(int i = 1; i < n - 1; i++)
        if(a[i] < 0 && a[i - 1] > 0 && a[i + 1] > 0)
            if(a[i] + a[i + 1] > 0 && a[i] + a[i - 1] > 0) {printf("NO.\n"); return;}
        
    
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

        // for(int i = 0; i < n; i++)
        //     printf("%d ", a[i]);
        // printf("\n");
        
        runs(a, n);
        free(a);
    }
    
    return 0;
}