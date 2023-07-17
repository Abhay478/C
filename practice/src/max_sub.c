
#include "my_header.h"

typedef struct this{
    int a, b, sum;
} Sub;

void max(int * a)
{
    Sub * s = malloc(2*sizeof(Sub));
    s[0].sum = 1;
    int i = 1;
    int k = 1;
    int sum = 0;
    while(a[i + 1] < a[i] && i < a[0]) i++;
    while(i <= a[0]){
        sum = 0;
        for(;a[i] >= a[k] && i <= a[0]; i++)
            if(a[i] - a[k] > sum) sum = a[i] - a[k];
        
        s[s[0].sum].sum = sum;
        s[s[0].sum].a = k;
        s[s[0].sum].b = i - 1;
        k = i;
        (s[0].sum)++;
        s = realloc(s, sizeof(int)*(s[0].sum + 1));
    }

    Sub * Sum = malloc(sizeof(Sub));
    Sum->sum = 0;
    Sum->a = 0;
    Sum->b = 0;
    for(i = 1; i < s[0].sum; i++){
        if(s[i].sum > sum){
            Sum->sum = s[i].sum;
            Sum->a = s[i].a;
            Sum->b = s[i].b;
        }
    }


    
    free(s);

    printf("%d\t%d\t%d\n", Sum->sum, Sum->a, Sum->b);
    free(a);
    free(Sum);

}

int main(void)
{
    int * a;
    Init_pointer(&a, 11, 12, 3, 6, 8, 10, 16, 18, 14, 2, 18, 20);
    max(a);

    return 0;
}