
#include "my_header.h"

typedef struct o{
    int n;
    char c;
} El;

//create a correspondence struct between the string and [n]. Sort string characters, obtaining corresponding int array. 

char * stsort(char * s)
{
    int l = strlen(s);
    char * out = malloc((l + 1)*sizeof(char));
    strcpy(out, s);
    InSort(&out);
    out[l] = 0;
    return out;
}

El ** make_el(char * sr)
{
    int l = strlen(sr);
    El ** out = malloc(l*sizeof(El *));
    for(int i = 0; i < l; i++){
        out[i] = malloc(sizeof(El));
        out[i]->n = i + 1;
        out[i]->c = sr[i];
    }
    return out;
}

int * get_arr(El ** a, int l)
{
    for(int i = 1; i < l; i++){
        char x = a[i]->c;
        int j;
        for(j = i - 1; j>= 0 && a[j]->c > x; j--)
            a[j+1] = a[j];
    
        a[j+1] = a[i];
    }

    int * out = malloc((l + 1)*sizeof(int));
    out[0] = l;
    for(int i = 1; i <= l; i++)
        out[i] = a[i]->n;
    
    return out;
}

//evaluate the array until some integer has index higher than itself. (*out) += (a[i] - i) * ((a[0] == i) ? 0 : Fact(a[0] - i));
//recurse : pass remaining int array as a string.
//since out is passed by refernce, increments through the rec. stack will set the value as necessary.
void A2I(char * s, int * out)
{
    int l = strlen(s);
    if(l == 2){
        (*out) += (s[0] > s[1]) ? 1 : 0;
        return;
    }
    char * sr = stsort(s);
    El ** e = make_el(sr);
    int * a = get_arr(e, l);

    int i;
    for(i = 1; i <= l && a[i] > i; i++){
        (*out) += (a[i] - i) * ((a[0] == i) ? 0 : Fact(a[0] - i));
    }
    if(i >= l){
        free(sr);
        free(a);
        for(int k = 0; k < l; k++){
            free(e[k]);
        }
        free(e);
        return;
    }
    char * new = malloc((l - i + 2)*sizeof(char));
    new[l - i + 2] = 0;
    for(int j = i; j <= l; j++){
        new[j] = a[j] + '0';
    }
    A2I(new, out);
    free(sr);
    free(a);
    for(int k = 0; k < l; k++)
        free(e[k]);
        
    free(e);
    return;
}

int main()
{
    printf("!");
    int out = 0;
    A2I("abcde", &out);
}