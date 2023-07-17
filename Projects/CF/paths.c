
#include <stdio.h>

int main(){
    int N = 0;
    scanf("%d", &N);
    
    unsigned long long int n, m;

    for(int q = 0; q < N; q++){
        scanf("%llu %llu", &n, &m);
        printf("%llu\n", m*(m - 1 + n*n + n) / 2);
    }
    
    return 0;
}