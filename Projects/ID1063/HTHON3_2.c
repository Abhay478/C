
#include <stdio.h>
#include <stdlib.h>


int length(char * s)
{
    int i;
    for(i = 0; s[i] != 0; i++)
        ;

    return i - 1;
}

int compare(char * s1, char * s2)
{
    int l1 = length(s1);
    int l2 = length(s2);
    if(l1 != l2) return l1 - l2;
    int i;
    for(i = 0; (s1[i] == s2[i]) && i < l1; i++);
    return s1[i] - s2[i];
}

char * Operate(char * s1, char * s2, int n1, int n2)
{
    int sig1 = 1, sig2 = 1;
    if(s1[0] == '-'){
        sig1 = -1;
        s1++;
        n1--;
    }
    if(s2[0] == '-') {
        sig2 = -1;
        s2++;
        n2--;
    }
    
    int x = 0;
    int max = (n1 < n2) ? n2 : n1;

    char * out = (char *)calloc(max + 2, sizeof(char));

    int c = compare(s1, s2);

    if(sig1 + sig2 != 0){
        int carry = 0;
        for(int i = 0; i <= max; i++){
            x = ((i < n1) ? (s1[n1 - i - 1] - '0') : 0) + ((i < n2) ? (s2[n2 - i - 1] - '0') : 0) + carry;
            out[max - i + 1] = x%10 + '0';
            carry = x/10;
        }
        if(out[1] == '0'){
            out++;
            out[-1] = '$';
        } 
        if(sig1 == -1) out[0] = '-';
        else{
            out++;
            out[-1] = '$';
        } 
    }
    
    else{
        if(c == 0){
            free(out);
            return "0";
        }
        out++;
        out[-1] = '$';

        int * sub = malloc(max*sizeof(int));
        sub[0] = ((max == n1) ? s1[0] - '0': 0) - ((max == n2) ? s2[0] - '0': 0);
        for(int i = 1; i < max; i++){
            sub[i] = ((i >= max - n1) ? s1[i + n1 - max] - '0': 0) - ((i >= max - n2) ? s2[i + n2 - max] - '0': 0);
            if(sub[0] < 0) sub[i] *= -1;
            if(sub[i] < 0){
                sub[i] += 10;
                
                //serial borrows
                if(sub[i - 1] == 0){
                    int j;
                    for(j = i - 1; j >= 0 && sub[j] == 0; j--)
                        sub[j] = 9;
                    if(j != 0) sub[j]--;
                }
                //ordinary borrow
                else sub[i-1]--;
            }
        }
        

        for(int i = 0; i < max; i++)
            out[i + 1] = sub[i] + '0';
        
        if(compare(s1, s2) < 0 && sig2 == -1) out[0] = '-';
        else if(compare(s1, s2) > 0 && sig1 == -1) out[0] = '-';
        else{
            out++;
            out[-1] = '$';
        }

        free(sub);

    }
    
    return out;
}
/*
char * Add(unsigned long int * a1, unsigned long int * a2, int op)
{
    int carry = 0;

    int max = fmax(a1[0], a2[0]);
    unsigned long int * sum = calloc(max, sizeof(int));

    if(op == 0)
        for(int i = 0; i < max; i++){
            sum[max - i] = ((i < a1[0] - 1) ? a1[a1[0] - i] : 0) + ((i < a2[0] - 1) ? a2[a2[0] - i] : 0) + carry;
            if(sum[max - i] > DIV) carry = 1;
        }
    else
        for(int i = 0; i < max; i++){
            sum[max - i] = ((i < a1[0] - 1) ? a1[a1[0] - i] : 0) - ((i < a2[0] - 1) ? a2[a2[0] - i] : 0) + carry;
            if(sum[max - i] < 0) carry = -1;
        }

    char * out = malloc(length*sizeof(char));

    if(op && (a1[0] > a2[0] || a1[1] > a2[1] || a1[2] > a2[2]))

    return out;
}

void allocate(char * s, int n1, unsigned long int * a, int n2){
    a[0] = n2;
    for(int i = n1 - 1; i >= 0; i--){
        a[n2 - 1 - i/16] += (s[i] - '0');
        a[n2 - 1 - i/16] *= 10;
        if(i%16 == 15) a[n2 - 1 - i/16] /= 10;
    }  
}*/

int main()
{
    unsigned long int n1 = 0, n2 = 0;
    char * s1 = NULL, * s2 = NULL, * s3 = NULL;

    while((getline(&s1, &n1, stdin) != -1) && (getline(&s2, &n2, stdin) != -1)){

        n1 = length(s1);
        n2 = length(s2);
        
        if(compare(s1, s2) > 0) s3 = Operate(s1, s2, n1, n2);
        else s3 = Operate(s2, s1, n2, n1);
        
        int i = 0;
        if(s3[0] == 0)
            for(; s3[i] == '0'; i++);
        else if(s3[0] == '-'){
            printf("-");
            i++;
            for(; s3[i] == '0'; i++);
        }
        printf("%s\n", s3 + i);
    }  

        

    free(s1);
    free(s2);
    if(s3[-2] == '$') free(s3 - 2);
    else if(s3[-1] == '$') free(s3 - 1);
    else free(s3);
    

    return 0;
}