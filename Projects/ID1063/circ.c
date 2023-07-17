
#include <stdio.h>
#include <stdlib.h>

int * zig(int * row, int l)
{
    int * out = (int *)malloc(l*sizeof(int));
    out[0] = row[l - 1];
    for(int i = 1; i < l; i++)
        out[i] = row[i - 1];

    return out;
}

int * zag(int * row, int l)
{
    int * out = (int *)malloc(l*sizeof(int));
    out[l - 1] = row[0];
    for(int i = 1; i < l; i++)
        out[i - 1] = row[i];

    return out;
}

int ** Accept(int n)
{
    int ** out = (int **)malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++){
        out[i] = (int *)malloc(n*sizeof(int));
        for(int j= 0; j < n; j++){
            scanf("%d", &out[i][j]);
        }
    }

    return out;
}

int comp(int * a, int * b, int n)
{
    for(int i = 0; i < n; i++)
        if(a[i] != b[i]) return 0;
    return 1;
}

void check(int ** a, int n)
{
    int * dummy;
    for(int i = 1; i < n; i++){
        dummy = zig(a[i], n);
        if(comp(dummy, a[i - 1], n) == 0){
            free(dummy);
            dummy = zag(a[i], n);
            if(comp(dummy, a[i - 1], n) == 0){
                printf("No\n");
                free(dummy);
                return;
            }
        }
        free(dummy);
    }
    printf("Yes\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int ** mat = Accept(n);
    check(mat, n);

    for(int i = 0; i < n; i++)
        free(mat[i]);
    

    free(mat);
    return 0;
}