
#include "my_header.h"

int min(int a, int b, int c)
{
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int ** path_mat(int ** cost)
{
    int m = cost[0][0];
    int n = cost[0][1];
    int ** out = (int **)calloc(m + 1, sizeof(int *));

    out[0] = (int *)calloc(2, sizeof(int));
    out[0][0] = m;
    out[0][1] = n;
    out[1] = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
        out[1][i] = cost[1][i];

    for(int i = 2; i <= m; i++){
        out[i] = (int *)calloc(n, sizeof(int));
        out[i][0] = cost[i][0] + fmin(out[i - 1][0], out[i - 1][1]);
        for(int j = 1; j < n - 1; j++){
            out[i][j] = cost[i][j] + min(out[i - 1][j], out[i - 1][j - 1], out[i - 1][j + 1]);
        }
        out[i][n - 1] = cost[i][n - 1] + fmin(out[i - 1][n - 1], out[i - 1][n - 2]);
    }

    return out;
}

int ** form()
{
    int rows;
    scanf("%d", &rows);
    int columns;
    scanf("%d", &columns);

    int ** out = (int **)calloc(rows + 1, sizeof(int *));
    out[0] = (int *)calloc(2, sizeof(int));
    out[0][0] = rows;
    out[0][1] = columns;

    for(int i = 1; i <= rows; i++){
        out[i] = (int *)calloc(columns, sizeof(int));
        for(int j = 0; j < columns; j++)
            scanf("%d", &(out[i][j]));
    }
        
    return out;

}

void mprint(int ** a)
{
    printf("\n");
    for(int i = 1; i <= a[0][0]; i++){
        for(int j = 0; j < a[0][1]; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void get_path(int r, int c, int ** fin, int ** init)
{
    printf("\n");
    printf("(%d, %d) : %d \n", r, c + 1, init[r][c]);
    int key;
    int i = r;
    while(i > 0){
        key = fin[i][c] - init[i][c];
        i--;
        if(fin[i][c] == key) printf("(%d, %d) : %d \n", i, c + 1, init[i][c]);
        else if(c != 0 && fin[i][c - 1] == key){
            c--;
            printf("(%d, %d) : %d \n", i, c + 1, init[i][c]);
        }
        else if(c != fin[0][1] - 1 && fin[i][c + 1] == key){
            c++;
            printf("(%d, %d) : %d \n", i, c + 1, init[i][c]);
        }
    }
    printf("\n");
}

int main()
{
    int ** m1 = form();
    int ** m2 = path_mat(m1);
    mprint(m2);
    for(int i = 0; i < m2[0][1]; i++)
        get_path(m2[0][0], i, m2, m1);
    for(int i = 1; i < m1[0][0]; i++)
    return 0;
}
