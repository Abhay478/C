
#include "my_header.h"

double hump(double x, double r)
{
    return r*x*(1 - x);
}

double Mandel(J num){
    J z = 0;
    
}

int main()
{
    double x, r;
    scanf("%lf %lf", &x, &r);

    while(hump(x, r) != x){
        x = hump(x, r);
    }

    printf("%lf\n", x);
}