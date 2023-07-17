
#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int max;
    int num;
    int i;
    int j;
} node;
/*
//creates a list from the matrix elements
node * list(node *** a, int n)
{
    node * head = a[0][0];
    
    int k = 0;
    int i = 0, j = 0;
    while(i != n - 1 || j != 0){
        if(i == n - 1){
            a[i][j]->next = a[n - j][0];
            i = n - j;
            j = 0;
        }
        else{
            a[i][j]->next = a[i + 1][j + 1];
            i++;
            j++;
        }
    }
    while(i != 0 || j != n - 1){
        if(j == n - 1){
            a[i][j]->next = a[0][n - i];
            j = n - i;
            i = 0;
        }
        else{
            a[i][j]->next = a[i + 1][j + 1];
            i++;
            j++;
        }
    }

    return head;
}

//dynamic part.
void set(node *** a, node * head, int n)
{
    node * current = head;
    current->max = current->num;
    while(current != NULL){
        if(current->i != 0){
            if(a[current->i - 1][current->j]->max - a[current->i - 1][current->j]->num < current->max){
                a[current->i - 1][current->j]->max = current->max + a[current->i - 1][current->j]->num;
            }
        }
        if(current->j != n - 1){
            if(a[current->i][current->j + 1]->max - a[current->i][current->j + 1]->num < current->max){
                a[current->i][current->j + 1]->max = current->max + a[current->i][current->j + 1]->num;
            }
        }
        current = current->next;
    }
    printf("%d\n", a[0][n - 1]->max);
}

//creates a struct matrix from the int matrix
node *** create(int ** a, int n)
{
    node *** out = (node ***)malloc(n*sizeof(node **));
    for(int i = 0; i < n; i++){
        out[i] = (node **)malloc((n - i)*sizeof(node *));
        for(int j = 0; j < n - i; j++){
            out[i][j] = (node *)malloc(sizeof(node));
            out[i][j]->i = i;
            out[i][j]->j = j;
            out[i][j]->max = 0;
            out[i][j]->next = NULL;
            out[i][j]->num = a[i][j];
        }
    }
    return out;
}

//scanf in a loop, returns int matrix
int ** Accept(int n)
{
    int ** out = (int **)malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++){
        out[i] = (int *)malloc((n - i)*sizeof(int));
        for(int j = 0; j < n - i; j++){
            scanf("%d", &out[i][j]);
        }
    }

    return out;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ** mat = Accept(n);
    node *** lat = create(mat, n);
    node * head = list(lat, n);
    set(lat, head, n);


    for(int i = 0; i < n; i++){
        free(mat[i]);
        for(int j = 0; j < n; j++){
            free(lat[i][j]);
        }
        free(lat[i]);
    }

    free(mat);
    free(lat);

    return 0;
}*/

int ** Accept(int n)
{
    int ** out = malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++){
        out[i] = malloc((i + 1)*sizeof(int));
        for(int j = 0; j <= i; j++)
            scanf("%d", &out[i][j]);
    }
    return out;
}

node *** create(int ** a, int n)
{
    node *** out = (node ***)malloc(n*sizeof(node **));
    for(int i = 0; i < n; i++){
        out[i] = (node **)malloc((n - i)*sizeof(node *));
        for(int j = 0; j < n - i; j++){
            out[i][j] = (node *)malloc(sizeof(node));
            out[i][j]->i = i;
            out[i][j]->j = j;
            out[i][j]->max = 0;
            out[i][j]->num = a[i][j];
        }
    }
    return out;
}

int set(node *** a, int n)
{
    a[0][0]->max = a[0][0]->num;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j <= i; j++){
            if(a[i][j]->max + a[i + 1][j + 1]->num > a[i + 1][j + 1]->max) a[i + 1][j + 1]->max = a[i][j]->max + a[i + 1][j + 1]->num;
            if(a[i][j]->max + a[i + 1][j]->num > a[i + 1][j]->max) a[i + 1][j]->max = a[i][j]->max + a[i + 1][j]->num;            
        }
    }

    int m = 0;
    for(int i = 0; i < n; i++)
        if(a[n - 1][i]->max > m) m = a[n - 1][i]->max;
    return m;
}

int main()
{
    int ** mat = Accept(15);
    node *** lat = create(mat, 15);
    int out = set(lat,  15);

    printf("%d\n", out);
    return 0;
}