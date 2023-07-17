
/* 5th Jan 2022
Name : Abhay Shankar K
Roll No : cs21btech11001
problem 1
*/
#include <stdio.h>

int sqr_diff(int n)
{
    int s;
    for(int i = 1; i <= n; i++){
        if(s + i*i*i - i*i < 32767)
            s += i*i*i - i*i;
        
    }
    return s;   
}

int main()
{
    int n;
    int a[30];
    int i;
    for(i = 0; scanf("%d", &n) != -1; i++){
        a[i] = sqr_diff(n);
    }

    for(int j = 0; j <= i; j++){
        printf("%d\n", a[j]);
    }

}