
#include "my_header.h"

T fact(T k)
{
    if(k == 0)
        return 1;
    return k*fact(k - 1);
}

int main(void)
{
    T n = *(int *)Get("Number", "int");
    printf("%llu", fact(n));
    return 0;
}