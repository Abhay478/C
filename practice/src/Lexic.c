
#include "my_header.h"

void Step(int * a)
{

    int least = pow(2, sizeof(int)) - 1;
    int i;
    for(i = a[0] - 1; a[i] > a[i + 1]; i--);
    for(int k = i; k <= a[0]; k++)
        if(a[least] > a[k] && a[k] > a[i]) least = k;

    int t = a[i];
    a[i] = a[least];
    a[least] = t;   

    int r = i + 1;
    int s = a[0];

    for(int r = i + 1, s = a[0]; r < s; r++, s--){
        t = a[r];
        a[r] = a[s];
        a[s] = t;
    }
    for(int m = 1; m <= a[0]; m++)
        printf("%d ", a[m]);
    printf("\n");
}

bool cmp(int * a, int * b)
{
    
    for(int i = 0; i <= a[0]; i++)
        if(a[i] != b[i]) return false;

    return true;
}

int Z_Lex(int * a)
{
    int sr[a[0] + 1];
    sr[0] = a[0];
    for(int m = 1; m <= a[0]; m++)
        sr[m] = m - 1;
    /*for(int i = 0; i <= a[0]; i++)
        sr[i] = a[i];
    
    for(int m = 1; m <= sr[0]; m++)
        printf("%d ", sr[m]);
    printf("\n");*/

    //InTSort(&sr);
    for(int m = 1; m <= sr[0]; m++)
        printf("%d ", sr[m]);
    printf("\n");
    int i;
    //for(i = 1; !cmp(sr, a); i++)
        Step(sr);

    
    return i;

}



int S_Lex(char * s)
{
    int l = strlen(s);
    char * sr = malloc((l + 1)*sizeof(char));
    strcpy(sr, s);
    InSort(&sr);
    printf("%s\n", sr);

    int i, j;
    int * a = malloc(l + 1);
    a[0] = l;
    for(j = 1; j <= l; j++)
        a[i] = i - 1;

    
    for(i = 1; ; i++, Step(a)){
        for(j = 0; sr[a[j + 1]] != s[j] && j < l; j++);
            
        
        if(j == l){
            free(sr);
            free(a);
            return i;
        }
    }

    

}

int main()
{
    int a[] = {6, 3, 2, 1, 6, 5, 4};
    printf("%d\n", Z_Lex(a));
    return 0;
}