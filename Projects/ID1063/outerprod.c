
#include <stdio.h>
#include <stdlib.h>

//comptes outer product of vector arguments and returns matrix
int ** matrify(int * a, int * b)
{
    int ** out = (int **)malloc((a[0] + 1)*sizeof(int *));
    out[0] = (int *)malloc(2*sizeof(int));
    out[0][0] = a[0];
    out[0][1] = b[0];
    for(int i = 1; i <= a[0]; i++){
        out[i] = (int *)malloc(b[0]*sizeof(int));
        for(int j = 1; j <= b[0]; j++){
            out[i][j - 1] = a[i]*b[j];
        }
    }
    return out;
}

int ** Accept()
{
    int m;
    scanf("%d", &m);
    int n;
    scanf("%d", &n);
    int * a = malloc((m + 1)*sizeof(int));
    int * b = malloc((n + 1)*sizeof(int));
    a[0] = m;
    b[0] = n;

    for(int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    int ** out = malloc(2*sizeof(int *));
    out[0] = a;
    out[1] = b;
    return out;
}

void print(int ** a)
{
    for(int i = 1; i <= a[0][0]; i++){
        for(int j = 0; j < a[0][1]; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int ** in = Accept();
    int ** prod = matrify(in[0], in[1]);
    print(prod);
    free(in[0]);
    free(in[1]);
    free(in);
    for(int i = 1; i <= prod[0][0]; i++)
        free(prod[i]);
    
    free(prod[0]);
    free(prod);
    return 0;
}