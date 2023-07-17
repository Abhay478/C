
#include <stdio.h>
#include <stddef.h>

int main(){
    int a = 10;
    int *p_a = NULL;
    p_a = &a;
    printf("%d-------\n", *p_a);
    return 0;
}

