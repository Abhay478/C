

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swapString(char s1[50], char s2[50]);
void sortString(char String_Array[10][50]);

int main(){
    /*char a1[3] = "abc";
    char a2[3] = "xyz";
    swapString(a1, a2);
    printf("%s\n%s", a1, a2);*/
    char input[10][50] = {"a", "abcd", "ab", "abcde", "", "abc", "abcdef","abcdefgh", "abcdefg", "abcdefghi"};
    sortString(input);
    /*for(int a = 0; a<10; ++a){
        printf("%s\n", input[a]);
    }*/

    return 0;
}

void swapString(char s1[50], char s2[50]){
    char temp[50];
    strcpy(temp,s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}

void sortString(char String_Array[10][50]){
    char m[50];
    int n;
    for(int i = 0;i < 10; ++i){
        strcpy(m, String_Array[i]);
        for(int j = i; j < 10; ++j){
            if(strcmp(String_Array[j], m)>0){
                strcpy(m, String_Array[j]);
                n = j;
            } 
        }
        printf("\n%s\n", m);
        swapString(String_Array[i], String_Array[n]);
    }
}