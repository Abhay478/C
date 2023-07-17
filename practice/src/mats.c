#include <stdio.h>
#include <stdlib.h>

typedef struct Mat{
    int ** m;
    int r; int c;
} Mat;

void print(Mat * mat)
{
    for(int i = 0; i < mat->r; i++){
        for(int j = 0; j < mat->c; j++){
            printf("%d ", mat->m[i][j]);
        }
        printf("\n");
    }
}

Mat * mult(Mat * m1, Mat * m2)
{
    int ** m = calloc(m1->r, sizeof(int *));
    for(int i = 0; i < m1->r; i++){
        m[i] = calloc(m2->c, sizeof(int));
        for(int j = 0; j < m2->c; j++){
            for(int k = 0; k < m1->c; k++){
                m[i][j] += m1->m[i][k] * m2->m[k][j];
            }
        }
    }

    Mat * out = calloc(1, sizeof(Mat));
    out->m = m;
    out->c = m2->c;
    out->r = m1->r;

    print(out);
    return out;
}

Mat * input()
{
    printf("Enter rows.\n");
    int r1;
    scanf("%d", &r1);
    printf("Enter cols.\n");
    int c1;
    scanf("%d", &c1);

    printf("Dim : %d, %d\n", r1, c1);
    printf("Enter.\n");
    int ** m1 = calloc(r1, sizeof(int *));
    for(int i = 0; i < r1; i++){
        m1[i] = calloc(c1, sizeof(int));
        for(int j = 0; j < c1; j++){
            scanf("%d", m1[i] + j);
        }
    }

    Mat * out = calloc(1, sizeof(Mat));
    out->m = m1;
    out->c = c1;
    out->r = r1;

    return out;
}

int main()
{
    printf("1.\n");
    Mat * m1 = input();
    

    // print(m1);

    printf("2.\n");
    Mat * m2 = input();
    // print(m2);
    
    mult(m1, m2);
}