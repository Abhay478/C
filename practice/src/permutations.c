#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int * a, int n)
{
    for(int i = 0; n + i < a[0] - i; i++){
        int temp = a[n + i];
        a[n + i] = a[a[0] - i];
        a[a[0] - i] = temp;
    }
}

void reverse_string(char * a)
{
    int l = strlen(a);
    for(int i = 0; i <= (l - 1) / 2; i++){
        // printf("Inside: %s\n", a);
        char temp = a[i];
        a[i] = a[l - i - 1];
        a[l - i - 1] = temp;
    }
}

void permute(char * s)
{
    int l = strlen(s), n, k;
    while(1){
        printf("%s\n", s);
        n = l - 2;
        
        while(s[n] >= s[n + 1] && n >= 0)
            n--;

        int mi = n + 1;
        for(int i = n + 1; i < l; i++)
            if(s[i] > s[n] && s[i] < s[mi]) 
                mi = i;
        
        if(n < 0) return;

        char temp = s[mi];
        s[mi] = s[n];
        s[n] = temp;

        reverse_string(s + n + 1);

    }
    
    
}

int cmp(const void * v1, const void * v2){
    char a = *(char *)v1;
    char b = *(char *)v2;

    return a - b;
}

int main(int argc, char * argv[])
{
    char * s;
    int l;
    if(argc != 2){
        s = malloc(1);
        size_t n = 0;
        getline(&s, &n, stdin);
        l = strlen(s);
        s[l - 1] = 0;
    }
    else {
        s = argv[1];
        l = strlen(s);
    }

    qsort(s, l - 1, sizeof(char), cmp);
    permute(s);

    if(argc != 2) free(s);

    return 0;
}