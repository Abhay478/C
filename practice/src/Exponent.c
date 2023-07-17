//Exponent

#include <stdio.h>

long pow(long a, long x);
int main(){
    printf("Enter base.");
    long a1, x1;
    scanf("%ld", &a1);
    printf("\nEnter exponent.");
    scanf("%ld", &x1);
    printf("\nBase raised to the exponent is : %ld", pow(a1, x1));
    return 0;
}

long pow(long a, long x){
    long p = 1;
    for(long i = 1; i<=x; i++){
        p *= a;
    }
    return p;
}