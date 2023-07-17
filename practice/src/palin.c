
#include "my_header.h"

void InSort(char ** A)
{
    int l = strlen(*A);
    for(int i = 1; i < l; i++){
        char x = (*A)[i];
        int j;
        for(j = i - 1; j>= 0 && (*A)[j] > x; j--)
            (*A)[j+1] = (*A)[j];
    
        (*A)[j+1] = x;
    }  
}

void InTSort(int ** A)
{
    for(int i = 2; i <= (*A)[0]; i++){
        int x = (*A)[i];
        int j;
        for(j = i - 1; j>= 0 && (*A)[j] > x; j--)
            (*A)[j+1] = (*A)[j];
    
        (*A)[j+1] = x;
    }  
    
}

bool isPal(char * s)
{
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] != s[strlen(s) - i - 1])
            return 0;
    return 1;
}
int sgn(void * v1, void * v2)
{
    if(*(char *)v1 == *(char *)v2) return 0;
    else if (*(char *)v1 < *(char *)v2) return -1;
    else return 1;
}

bool isAnag(char * s1, char * s2)
{
    if(strlen(s1) != strlen(s2)) return 0;
    else{
        InSort(&s1);
        InSort(&s2);
        if(strcmp(s1, s2) != 0) return 0;
        else return 1;
    }
}

