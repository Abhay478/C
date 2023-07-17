
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool * bits(int * a, int n){
    bool * out = malloc(n * sizeof(bool));
    for(int i = 0; i < n; i++)
        out[i] = (a[i]%2);
    
    for(int i = n - 1; i > 0; i--)
        out[i] = out[i] ^ out[i - 1];
    out++;

    // for(int i = 0; i < n - 1; i++)
    //     printf("%d ", out[i]);
    // printf("\n");
    
    return out;
}

int subs(bool * bits, int n)
{
    int count = 0;
    int run = 0;

    // for(int i = 0; i < n; i++)
    //     printf("%d ", bits[i]);
    // printf("\n");

    for(int i = 0; i < n; i++){
        if(bits[i]) run++;
        else{
            count += (run != 1) ? (int) run / 2 : 1;
            run = 0;
        }
    }
    count += (run != 1) ? (int) run / 2 : 1;

    return count;
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
        bool * bit = bits(a, n);
        printf("%d\n", subs(bit, n - 1));
        free(--bit);
        free(a);
    }
    
    return 0;
}