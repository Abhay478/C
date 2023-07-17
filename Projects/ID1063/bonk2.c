
#include <stdio.h>
#include <stdlib.h>

int length(char * s)
{
    int i = 0;
    for(; s[i] != '\0'; i++);
    return i - 1;

}

int compare(char * s1, char * s2)
{
    if(length(s1) != length(s2)) return length(s1) - length(s2);
    int i;
    for(i = 0; (s1[i] == s2[i]) && i < length(s1); i++);
    return s1[i] - s2[i];
}

void Operate(char * s1, char * s2, char ** out, int op)
{
    int l1 = length(s1);
    int l2 = length(s2);
    int max = l1 > l2 ? l1 : l2;

    *out = calloc(max + 1, sizeof(char));
    if(op == 0){
        int carry = 0;
        int x = 0;
        for(int i = 0; i < max; i++){
            x = ((i <= l1) ? s1[l1 - i] : 0) + ((i <= l2) ? s2[l2 - i] : 0);
            (*out)[max - i] = x%10 + carry;
            carry = x/10;
        }
    }
    if(op == 1){
        int borrow = 0;
        int x = 0;
        if(s1[0] == '-'){
            s1++;
            l1--;
        }
        if(s2[0] == '-'){

        }
        for(int i = 0; i < max; i++){
            x = ((i <= l1) ? s1[l1 - i] : 0) - ((i <= l2) ? s2[l2 - i] : 0);
            (*out)[max - i] = 0;
        }
    }

    

}

int main()
{
    unsigned long int n1 = 0, n2 = 0;
    char * s1 = NULL, * s2 = NULL, * s3 = NULL;

    while((getline(&s1, &n1, stdin) != -1) && (getline(&s2, &n2, stdin) != -1)){
        n1 = length(s1) - 1;
        n2 = length(s2) - 1;

        //lops off trailing newline
        s1 = realloc(s1, n1);
        s2 = realloc(s2, n2);

        //figures out operation
        int op = 0;
        if((s1[0] == '-') ^ (s2[0] == '-')) op = 1;
        if((s1[0] == '-') && (s2[0] == '-')) printf("-");

        //performs operation
        Operate(s1, s2, &s3, op);
        printf("%s\n", s3);
    }
}