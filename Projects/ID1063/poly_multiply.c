
#include <stdio.h>
#include <stdlib.h>

int len(char * s)
{
    int i;
    for(i = 0; s[i] != 0; i++);
    return i;
}

int * get_coefs(int * a, int * b)
{
    int deg = a[0] + b[0] - 1;
    int * out = malloc((deg + 1)*sizeof(int));
    out[0] = deg;
    int coef = 0;
    for(int i = 1; i <= out[0]; i++){
        for(int j = 1; j <= i; j++){
            coef += ((j <= a[0]) ? a[j] : 0) * ((i - j + 1 <= b[0]) ? b[i - j + 1] : 0);
        }
        out[i] = coef;
        coef = 0;
    }

    return out;
}

void reverse(char * s) 
{
    int temp;
    int l = len(s);
    for(int i = 0; i < l/2; i++){
        temp = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = temp;
    }
}

int * get_int(char * s, int length)
{
    int l = len(s);
    int * out = calloc((length + 1), sizeof(int));
    out[0] = l;
    for(int i = 1; i <= length; i++){
        out[i] = (i <= l) ? s[l - i] - '0' : 0;
    }
    return out;
}

void printa(int * a)
{
    for(int i = 1; i <= a[0]; i++)
        printf("%d ", a[i]);
    
    printf("\n");
}

char * carry_over(int * coef)
{
    char * out = calloc(coef[0] + 1, sizeof(char));
    for(int i = 0; i <= coef[0]; i++)
        out[i] = '0';


    for(int i = 1; i <= coef[0]; i++){
        out[coef[0] + 1 - i] += coef[i]%10;
        coef[i + 1] += coef[i]/10;
    }
    
    out[0] += coef[coef[0]]/10;
    
    return out;
}


char * trim(char * a)
{
    int i;
    char * dummy = a;
    for(i = 0; a[i] == '0'; i++){
        dummy++;
    }
    return dummy;
}

int main()
{
    char * s1 = malloc(1);
    size_t n1 = 0;
    getline(&s1, &n1, stdin);
    n1 = len(s1);
    s1[n1 - 1] = 0;

    char * s2 = malloc(1);
    size_t n2 = 0;
    getline(&s2, &n2, stdin);
    n2 = len(s2);
    s2[n2 - 1] = 0;
    

    if(s1[0] == '-'){
        s1++;
        if(s2[0] != '-') printf("-");
    }
    if(s2[0] == '-'){
        s2++;
        if(s1[0] != '-') printf("-");
    }

    int n = (n1 >= n2) ? n1 : n2;

    
    int * coef_1 = get_int(s1, n);
    
    int * coef_2 = get_int(s2, n);
    

    int * new_coefs = get_coefs(coef_1, coef_2);
    
    char * prod = carry_over(new_coefs);
    char * out = trim(prod);
    printf("%s\n", out);

    free(coef_1);
    free(coef_2);
    free(new_coefs);
    free(prod);
    

    return 0;
}