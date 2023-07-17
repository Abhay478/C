
#include <stdio.h>
#define T unsigned long long int
void find(T n)
{
    if((n % 4) % 6 != 0 && (n % 6) % 4 != 0) {printf("-1\n"); return;}

    int max, min;
    if(n % 4 == 0) max = n / 4;
    if(n % 6 == 0) min = n / 6;

    
}

int main()
{
    int n;
    T cse;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &cse);
        find(cse);
    }
}