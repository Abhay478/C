
#include <stdio.h>
#include <stdlib.h>


void set(int ** a, int n)
{
    (*a) = calloc(n + 1, sizeof(int));
    for(int i = 1; i <= n; i++)
        (*a)[i] = 1;
}

void print(int * a, int n)
{
    for(int i = n; i > 0; i--)
        printf("%d ", a[i]);

    printf("\n");
}

void partition(int n)
{
    //step 1
    int * a = NULL;
    set(&a, n);
    //step 2 init
    a[0] = 1;
    a[1] = n;
    int m = 1;
    
    while(1){
        //step 3
        print(a, m);
        if(a[a[0]] == 2){
            //step 4
            a[a[0]--] = 1;
            m++;
        }
        else{
            //step 5
            if(a[0] == 0){
                free(a);
                return;
            }
            a[a[0]]--;
            n = m - a[0] + 1;
            m = a[0] + 1;

            //step 6
            while(n > a[a[0]] - 1){
                a[m] = a[a[0]] - 1;
                n -= a[a[0]] - 1;
                m++;
            }
            //step 2 iter
            a[m] = n;
            a[0] = m;
            while(a[a[0]] == 1)
                a[0]--;
            
        }
    }
}
/*
void partitions(int n)
{
    for(int m = 1; m <= n; m++){
        int * a = NULL;
        set(&a, n);

        a[1] = n - m + 1;
        while(1){
            print(a, m);
            if(a[2] > a[1] - 1){
                int j = 3;
                int s = a[1] + a[2] - 1;
                for(; a[j] > a[1] - 1; j++)
                    s += a[j];

                if(j > m) break;
                a[j]++;
                j--;
                while(j > 1){
                    a[j]++;
                    s -= a[j];
                }
                a[1] = s;
            }
            else{
                a[1]--;
                a[2]++;
            }
        }
    }
}*/

int main()
{
    int n;
    while(scanf("%d", &n) != -1)
        partition(n);

    return 0;
}