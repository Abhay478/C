

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
const static int MAXLEN = 100;
const int LENGTH = 10;

void swapString(char *s1, char *s2);
void sortString(char *String_Array[]);

int main()
{
    char * Array[LENGTH] = { NULL };
    printf("Enter strings.");
    int c = 0, i = 0;
    while(c != -1){
        c = getline(Array + i, &MAXLEN, stdin);
        i++;
    }
    sortString(Array);
    return 0;
}

void swapString(char *s1, char *s2){
    char *temp = malloc(MAXLEN * LENGTH);
    temp = s1;
    s1 = s2;
    s2 = temp;
}

void sortString(char *String_Array[]){
    char *m = malloc(MAXLEN * LENGTH);
    int n;
    for(int i = 0;i < LENGTH; i++){
        m = String_Array[i];
        for(int j = i; j < 10; j++){
            if(strcmp(String_Array[j], m)>0){
                strcpy(m, String_Array[j]);
                n = j;
            } 
        }
        printf("\n%s\n", m);
        swapString(String_Array[i], String_Array[n]);
    }
}
