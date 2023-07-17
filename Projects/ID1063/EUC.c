

/* 5th Jan 2022
Name : Abhay Shankar K
Roll No : cs21btech11001
problem 1
*/
#include <stdio.h>

int Euc_gcd(int a, int b)
{
    int n1, n2;
    if(a < b){
        n1 = a;
        n2 = b;
    }
    else{
        n1 = b;
        n2 = a;
    }

    int r;
    while(n1 >= 0){
        r = n2%n1;
        if(r==0)
            return n1;
        else{
            n2 = n1;
            n1 = r;
        }
    }

}

int main()
{
    int a, b;
    int f[30];
    int i;
    for(i = 0; scanf("%d %d", &a, &b) != -1; i++){
        f[i] = Euc_gcd(a, b);
    }
    for(int j = 0;j <= i; i++)
        printf("%d\n", f[j]);
    return 0;
}