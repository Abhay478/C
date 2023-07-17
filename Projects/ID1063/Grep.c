
/*
Name : Abhay Shankar K
Roll no. : cs21btech11001

Date : Feb 25.
*/

#include <stdio.h>
#include <stdlib.h>

//returns length of string argument. Similar to strlen
int length(char * s)
{
    int i;
    for(i = 0; s[i] != 0; i++);
    return i;
}

//checks if character is an uppercase letter, returns lowercase version if so. otherwise, returns character unchanged.
char Lower(char c)
{
    if((c >= 'A' && c <= 'Z')) return c + 32;
    else return c;
}

//returns 0 if two strings are identical in first n characters. variable 'cas' specifies case sensitivity
int compare(char * pat, char * exc, int n, int cas)
{
    
    if(length(pat) < n || length(exc) < n) return -1;
    for(int i = 0; i < n; i++){

        if(cas == 0 && pat[i] != exc[i] && pat[i] != '.') return -1;
        else if(cas == 1 && Lower(pat[i]) != Lower(exc[i]) && pat[i] != '.') return -1;
    }

    return 0;
}


//If the pattern is of the form "..." - only wildcard characters - then entire file is printed.
void printfull(FILE * f)
{
    char * buf = (char *)calloc(1, sizeof(char));
    int line_count;
    size_t c = 0;
    for(line_count = 1; getline(&buf, &c, f) != -1; line_count++)
        printf("%d : %s\n", line_count, buf);

    free(buf);
}

//prints each line that contains s.
void Find(FILE * f, char * s, int cas, int inv)
{
    int l = length(s);
    char * buf = calloc(1, sizeof(char));
    int i;
    size_t c = 0;
    char first = 0;
    for(i = 0; i < l && s[i] == '.'; i++);
    if(i == l){
        printfull(f);
        return;
    }
    if(i > 0) i--;
    first = s[i];

    int print_flag;
    int line_count;
    

    for(line_count = 1; getline(&buf, &c, f) != -1; line_count++){
        print_flag = 0;
        
        for(int j = i; j < length(buf); j++){
        //this is to ensure that there are enough characters in the line for all the dots in the string. 
        //It also checks for each occurrence of the first non-wildcard character, and then compares rest of s with the succeeding characters.

            if(buf[j] == s[i] || (cas == 1 && Lower(buf[j]) == Lower(s[i])))
                if(compare(s, buf + j, l, cas) == 0)
                    print_flag = 1;

        }
        
        if(inv == 0 && print_flag != 0) printf("%d : %s\n", line_count, buf);
        if(inv != 0 && print_flag == 0) printf("%d : %s\n", line_count, buf);

        
    }
}

//concatenates two string args(second before first)
char * concat(char * fn, char * in)
{
    int l = length(in);
    char * out = (char *)calloc(length(fn) + l + 1, sizeof(char));
    for(int i = 0; i < length(out); i++)
        out[i] = (i < l) ? in[i] : fn[i - l];
    
    return out;
}

int main(int argc, char * argv[])
{
    FILE * f = fopen(argv[argc - 1], "r");
    if(f == NULL) return -1;
    int i = 0, v = 0;
    if(argc == 4){
        switch(argv[1][1]){
            case 'v' : v = 1;
            break;

            case 'i' : i = 1;
            break;

            default : break;
        }
    }
    if(argc == 5){
        i = 1;
        v = 1;
    }

    Find(f, argv[argc - 2], i, v);
    
    return 0;
}

