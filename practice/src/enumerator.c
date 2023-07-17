
#include "my_header.h"

void enumerate(FILE * const I_f1, FILE * const I_f2);

int main()
{
    char * path1 = (char *)Get("path of word-array file", "string");
    
    FILE * P_W_A = fopen(path1, "r+"); //word array

    char * path2 = (char *)Get("path of text file", "string");
    
    FILE * P_T = fopen(path2, "r+"); //text

    enumerate(P_W_A, P_T);
    fclose(P_W_A);
    fclose(P_T);
    free(path1);
    free(path2);

    return 0;
}

void enumerate(FILE * const I_f1, FILE * const I_f2)
{
    char * s1 = NULL;
    char * s2 = NULL;
    long int count;
    int c1 = getc(I_f1);
    int c2 = getc(I_f2);
    while(c1 != EOF){
        ungetc(c1, I_f1);
        salloc(&s1, I_f1, ' ');
        
        count = 0;
        printf("%s : ",  s1);

        while(c2 != EOF){
            ungetc(c2, I_f2);
            salloc(&s2, I_f2, ' ');
            if(!strcmp(s1, s2))
                count++;
            
        }

        printf("%ld\n", count);
        free(s1);
        free(s2);
        c1 = getc(I_f1);
        c2 = getc(I_f2);
    }
}

