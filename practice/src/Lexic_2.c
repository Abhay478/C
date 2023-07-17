
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node{
    char * s;
    int * a;
    struct tree_node * lp;
    struct tree_node * rp;

} node;

char * Sort_string(char * a)
{
    int l = strlen(a);
    char * s = calloc(l + 1, sizeof(char));
    strcpy(s, a);
    int x, j;
    for(int i = 1; i < l; i++){
        x = s[i];
        for(j = i - 1; j >= 0 && s[j] > x; j--)
            s[j + 1] = s[j];
        
        s[j + 1] = x;
    }

    return s;
}

void printa(FILE * f, int * a)
{
    for(int i = 1; i <= a[0]; i++)
        fprintf(f, "%d ", a[i]);
    fprintf(f, "\n");
}

void Step(int l, FILE * f)
{
    int a[l + 1];
    a[0] = l;
    for(int i = 1; i <= l; i++)
        a[i] = i;

    printa(f, a);
    int count = 1;
    while(1){
        int m = 0;
        int n;
        int i;
        for(i = a[0] - 1; a[i] > a[i + 1] && i > 0; i--);

        if(i == 0){
            printf("%d\n", count);
            return;
        }
        n = i;
        for(int k = i; k <= a[0]; k++){
            if(m > a[k] && a[k] > a[i]){
                m = a[k];
                n = k;
            }
        }

        int t = a[i];
        a[i] = a[n];
        a[n] = t;

        int r = i + 1;
        int s = a[0];

        for(int r = i + 1, s = a[0]; r < s; r++, s--){
            t = a[r];
            a[r] = a[s];
            a[s] = t;
        }
        printa(f, a);
        count++;
        //if(count == 1000000) printa(stdout, a);
    }
    
}

node * Order(char * s, FILE * f)
{
    char * sr = Sort_string(s);

    node * root = (node *)malloc(sizeof(node));
    root->lp = NULL;
    root->rp = NULL;
    strcpy(root->s, s);
    (root->a)[0] = strlen(s);
    Step((root->a)[0], f);

    fclose(f);
    f = fopen("Lexes.txt", "r");

    return root;

}

int S_Lex(char * s)
{
    int l = strlen(s);
    if(l > 11) return -1;
    FILE * f = fopen("Lexes.txt", "w+");
    Step(l, f);
    fclose(f);
    f = fopen("Lexes.txt", "r");

    fseek(f, 0, SEEK_SET);
    
    int * a = malloc((l + 1)*sizeof(int));
    a[0] = l;
    int i;
    int count = 1;
    char * sr = Sort_string(s);
    while(1){
        for(i = 1; i <= l; i++)
            fscanf(f, "%d", a + i);
        
        
        for(i = 0; i < l; i++)
            if(sr[a[i + 1] - 1] != s[i]) break;

        if(i == l){
            fclose(f);
            free(a);
            free(sr);
            return count;
        }
        count++;
    }
}

int main()
{
    printf("%d\n", S_Lex("6754321"));
    
    return 0;
}