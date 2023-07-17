
#include <stdio.h>
#include <math.h>

int main()
{
    FILE * f = fopen("/Users/abhay/downloads/names.txt", "r+");
    char ** names = NULL;
    int c;
    char * s = (char *)calloc(20, sizeof(char));
    for(int i = 0; (c = getc(f)) != EOF; i++){
        ungetc(c, f);
        scanf("%s", s);
        names + i = 
    }
}