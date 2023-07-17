
#include <stdio.h>
#include <stdlib.h>

void print(int * a, int n){
    printf("%d", a[n - 1]);
    for(int i = n - 2; i >= 0; i--){
        printf("+%d", a[i]);
    }
    printf("\n");
}

void buckets(int n)
{
    if(n==0){
        printf("0\n");
        return;
    }

    int x = 0;
    int sum;

    int * a = calloc(n, sizeof(int));
    a[0] = n;

    while(1){
        //relevant output step
        print(a, x + 1);
        sum = 0; //resets value to be disributed

        //collects all trailing ones
        while(a[x] == 1){
            sum++;
            x--;

            //if every element of array is 1, then return
            if(x < 0){
                free(a);
                return;
            }
        }

        //decrements last non-unit value, increments sum
        a[x]--;
        sum++;

        //assigns a[x] to (int)(sum/a[x]) values, i.e., spreads sum equally over (int)(sum/a[x]) values;
        while(sum > a[x]){
            a[x + 1] = a[x];
            sum -= a[x];
            x++;
        }

        a[x + 1] = sum;
        x++;
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) != -1)
        buckets(n);
    
    return 0;
}