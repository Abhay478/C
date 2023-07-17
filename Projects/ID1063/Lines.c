
/*
Name : Abhay Shankar K
Roll no. : cs21btech11001

Date : Feb 25.
*/
#include <stdio.h>
#include <stdlib.h>

//prints n lines of file pointed to by f.
int lines(FILE * f, int n)
{
    char * buf = (char *)malloc(sizeof(char));
    size_t x = 0;
    for(int i = 1; i <= n; i++){
        x = getline(&buf, &x, f);
        printf("%s", buf);
        if(x == -1){
            free(buf);
            return -1;
        }
    }
    free(buf);
    return 0;
}


//returns length of string argument. Similar to strlen
int length(char * s)
{
    int i;
    for(i = 0; s[i] != 0; i++);
    return i;
}

//converts a string to an integer. Similar to atoi in stdlib.h.
int AtoI(char * s)
{
    int l = length(s);
    int out = s[0] - '0';
    for(int i = 1; i < l; i++){
        out *= 10;
        out += s[i] - '0';
    }

    return out;
}

int main(int argc, char * argv[])
{
    
    FILE * f = fopen(argv[2], "r");
    if(f == NULL) return -1;
    
    int out = AtoI(argv[1]);
    //printf("%d\n", out);
    int x = lines(f, out);
    
    char newline;
    while(scanf("%c", &newline) != -1 && x != -1)
        x = lines(f, 1);

    fclose(f);
    return 0;
    
}