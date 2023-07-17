
#include "my_header.h"


int * Lower_prec(int * a, int * b)
{
    int max = fmax(a[0], b[0]);
    int * out = calloc(max + 2, sizeof(int));
    for(int i = 0; i < max; i++){
        out[max + 1 - i] = ((i < a[0]) ? a[a[0] - i] : 0) + ((i < b[0]) ? b[b[0] - i] : 0);
    }
    return out;
}

int * multiply(int * a, int * b)
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

typedef struct mc{
    int * quo;
    int * rem;
} M;

int * get_pol(int val, int exp)
{
    int * out = calloc((exp + 2), sizeof(int));
    out[0] = exp;
    out[1] = val;
    return out;
}

int coef_cmp(int * a, int * b)
{
    if(a[0] != b[0]) return a[0] - b[0];

    int i;
    for(i = 1; i < a[0] && a[i] == b[i]; i++);
    return a[i] - b[i];
}

M * divide(int * num, int * den)
{
    M * res = malloc(sizeof(M));
    int deg_diff;
    for(int i = 0; ; i++){
        int * one = get_pol(1, i);
        int * two = multiply(den, one);
        if(coef_cmp(two, num) == 0){
            res->quo = two;
            res->rem = NULL;
            free(one);
            return res;
        }
        if(coef_cmp(two, num) > 0){
            deg_diff = i - 1;
            free(one);
            free(two);
            break;
        }
        free(one);
        free(two);
    }
    int * out = malloc((deg_diff + 2)*sizeof(int));
    int * three;
    int * sum;
    out[0] = deg_diff + 1;
    for(int i = deg_diff; i >= 0; i--){
        for(int j = 2; j <= 10; j++){
            three = get_pol(j, i);
            sum = Lower_prec(out, three);
            if(coef_cmp(sum, num) == 0){
                res->quo = sum;
                res->rem = NULL;
                free(three);
                free(out);
                return res;
            }
            if(coef_cmp(out, num) == 0){
                res->quo = out;
                res->rem = NULL;
                free(three);
                free(sum);
                return res;
            }
            if(coef_cmp(sum, num) > 0){
                out[deg_diff - i + 1] = j - 1;
                free(three);
                free(sum);
            }
            free(three);
            free(sum);
        }
    }

    int * sub = malloc((deg_diff + 2)*sizeof(int));
    sub[0] = out[0];
    for(int i = 1; i < deg_diff + 2; i++)
        sub[i] = -1*out[i];

    int * rm = Lower_prec(num, sub);
    free(sub);
    
    res->quo = out;
    res->rem = rm;
    return res;
}

char * carry_over(int * coef)
{
    //print(coef, ' ', 0);
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

int * get_int_line(FILE * f)
{
    char * s;
    size_t n;
    getline(&s, &n, f);
    int l = strlen(s);
    int * out = malloc((l + 1)*sizeof(int));
    out[0] = l;

    for(int i = 1; i <= out[0]; i++)
        out[i] = s[i - 1] - '0';

    return out;
}

int main()
{
    /*
    int * numerator = get_int_line(stdin);
    int * denominator = get_int_line(stdin);
    M * result = divide(numerator, denominator);
    printf("%s, %s\n", carry_over(result->quo), carry_over(result->rem));
    */

    int * one = get_int_line(stdin);
    int * two;
    int * three;
    for(int i = 1; i < 100; i++){
        two = get_int_line(stdin);
        three = one;
        one = Lower_prec(one, two);
        free(three);
        free(two);
    }
    char * out = carry_over(one);
    printf("%s\n", out);
    free(one);
    free(out);

    return 0;
}