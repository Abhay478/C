
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getb(char * s, int k, int q)
{
    k--;
    static int q_s = 0, q_t = 0;
    int n = strlen(s);
    for(int i = q?q_s:q_t; i < n; i++)
        if(s[i] == 'b') { 
            if(!k) {if(q) q_s=i; else q_t=i; return i;} else k--;}
    if(k) return -1;
}

void doi(char * s, char * t)
{
    int sw = 0;
    int s_b, t_b;
    for (int k = 1; sw <= 10000; k++){
        if(!strcmp(s, t)){printf("YES\n"); return;}
        s_b = getb(s, k, 1);
        t_b = getb(t, k, 0);
        if(!(s_b + 1 && t_b + 1)) {printf("NO\n"); return;}
        if(s_b < t_b) {printf("NO\n"); return;}
        s[s_b] = 'a';
        s[t_b] = 'b';

        sw += s_b - t_b;
    }
    
    {printf("NO\n"); return;}
    
}

int main()
{
    int N;
    scanf("%d", &N);

    int n;
    char * s;
    char * t;

    for(int q = 0; q < N; q++){
        scanf("%d", &n);
        s = malloc(n*sizeof(char));
        t = malloc(n*sizeof(char));

        scanf("%s\n%s", s, t);

        doi(s, t);
        free(s);
        free(t);
    }
}