
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int String_compare(char * one, char * two);

int main(int argc, char *argv[])
{
    
}
int String_compare(char * one, char * two)
{
    while((!(*one++))&&(!(*two++))){
        if(*one < *two)
            return -1;
        else if (*one > *two)
            return 1;
    }
    return 0;
}