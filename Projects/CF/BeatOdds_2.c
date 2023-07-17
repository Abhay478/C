#include <stdio.h>
#include <math.h>

int main()
{
    int N = 0;
    scanf("%d", &N);
    
    int n;

    for(int q = 0; q < N; q++){
        scanf("%d", &n);
        int a;
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &a);
            (a%2) ? c2++ : c1++;
        }

        printf("%d\n", (c1 < c2)? c1 : c2);
    }
    
    return 0;
}