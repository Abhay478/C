
/*
7th Jan, 2022
Problem 1

Roll Number:
Name: 

*/

#include <stdio.h>

int sum_cmp(int n, int a, int b)
{
    int sum = 0;
    for(int i = 1; i < n; i++)
        if((i%a == 0) || (i%b == 0)) sum += i;
    
    return sum;
}
int main() {
    int n,a,b;

    while(scanf("%d %d %d", &n,&a,&b) != -1) {
        printf("%d\n", sum_cmp(n, a, b));
    }
    return 0;
}
