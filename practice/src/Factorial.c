
#include "my_header.h"
#define T unsigned long long int
T fact(int x);

int main(int argc, char * argv[]){
    printf("Factorial is : %lld\n", fact(atoi(argv[1])));
    return 0;
}

T fact(int x)
{
    T k = 1;
    while(x > 0){
        k *= x;
        x--;
    }
    return k;
}
