
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void runs(int * a, int n)
{
    if(a[0] != a[1]) {printf("-1\n"); return;}
    if(a[n - 1] != a[n - 2]) {printf("-1\n"); return;}
    for(int i = 1; i < n - 1; i++)
        if(a[i] != a[i - 1] && a[i] != a[i + 1]) {printf("-1\n"); return;}
    
    int k = 1;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i - 1]){
            printf("%d ", i);
            for(int j = k; j < i; j++)
                printf("%d ", j);
            
            k = i + 1;
        }
    }
    printf("%d ", n);
    for(int j = k; j < n - 1; j++)
        printf("%d ", j);
    printf("%d\n", n - 1);
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