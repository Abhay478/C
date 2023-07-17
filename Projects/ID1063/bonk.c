
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 17

#define DIV 10000000000000000

//#define mod(n) ((n) > 0)?(n):(-1*n)

int length(char * s)
{
    int i = 0;
    for(; s[i] != '\0'; i++);
    return i - 1;

}

void allocate(char * s, unsigned long int ** a, int no_blocks)
{
    *a = calloc(no_blocks + 2, sizeof(unsigned long int));
    (*a)[0] = no_blocks;            //sets first element of array to array length

    int l = length(s);

    //converts string blocks to integers, then puts in array
    for(int i = 0; i < l; i++){
        (*a)[no_blocks + 1 - i/BLOCK_SIZE] += s[l - i] - '0';
        (*a)[no_blocks + 1 - i/BLOCK_SIZE] *= 10;
        if(BLOCK_SIZE - i%BLOCK_SIZE == 1) (*a)[no_blocks + 1 - i/BLOCK_SIZE] /= 10;
    }
}

void deallocate(char ** s, unsigned long int * a)
{
    *s = calloc(a[0]*BLOCK_SIZE, sizeof(char));

    //converts integers to string blocks.
    for(int i = 0; i < a[0]*BLOCK_SIZE; i++){
        (*s)[a[0]*BLOCK_SIZE - i] = a[a[0] + 1 - i/16]%10 + '0';
        a[a[0] + 1 - i/16] /= 10;
    }
}

char * Operate(unsigned long int * a1, unsigned long int * a2, int op)
{
    char * out = NULL;
    int max = (a1[0] > a2[0]) ? a1[0] : a2[0];
    unsigned long int * res = calloc(max + 2, sizeof(unsigned long int));
    res[0] = max;

    if(op == 0){
        int carry = 0;
        for(int i = max + 1; i > 0; i--){
            res[i] = ((a1[0] - max + i > 0) ? a1[a1[0] - max + i] : 0) + ((a2[0] - max + i > 0) ? a2[a2[0] - max + i] : 0) + carry;
            if(res[i] > DIV) carry = 1;
        }
    }
    if(op == 1){
        int borrow = 0;
        for(int i = max + 1; i > 0; i--){
            res[i] = ((a1[0] - max + i > 0) ? a1[a1[0] - max + i] : 0) - ((a2[0] - max + i > 0) ? a2[a2[0] - max + i] : 0) + borrow;
            //res[i] = abs(res[i]);
            if(res[i] < 0) borrow = -1;
        }
    }
    deallocate(&out, res);
    return out;
}

int main()
{
    char * s1 = NULL;
    int n1 = 0;
    unsigned long int * a1 = NULL;

    char * s2 = NULL;
    int n2 = 0;
    unsigned long int * a2 = NULL;

    char * s3 = NULL;

    //accepts input till EOF
    while(getline(&s1, &n1, stdin) != -1 && getline(&s2, &n2, stdin) != -1){

        //gets integer arrays
        allocate(s1, &a1, length(s1)/BLOCK_SIZE + 1);
        allocate(s2, &a2, length(s2)/BLOCK_SIZE + 1);

        //figures out operation
        int op = 0;
        if((s1[0] == '-') ^ (s2[0] == '-')) op = 1;

        //performs operation
        s3 = Operate(a1, a2, op);
        printf("%s\n", s3);
        free(a1);
        free(a2);
        free(s3);
    }
    return 0;
}