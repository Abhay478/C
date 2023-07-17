#include <stdio.h>
#include <stdlib.h>
typedef struct t{
    int n;
    struct t * left;
    struct t * right;
}