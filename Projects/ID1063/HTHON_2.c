
/*
7th Jan, 2022
Problem 2

Roll Number: cs21btech11001
Name: Abhay Shankar K

 */

#include<stdio.h>

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

void simplify(int a, int b)
{
    int gcd = Euc_gcd(a, b);
    printf("%d/%d\n", a/gcd, b/gcd);
}
int main(){
    int a,b;
  
    while(scanf("%d %d",&a,&b) != -1) {
        simplify(a, b);
    }
    return 0;  
}
