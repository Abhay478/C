
#include <stdio.h>

double invert(double x);

int main(){
    printf("Enter number.\n");
    double a;
    scanf("%lf", &a);
    printf("Inverse = %lf", invert(a));
    return 0;
}

double invert(double x){
    double k = 1/x;
    return k;
}