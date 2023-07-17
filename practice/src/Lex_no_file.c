#include "my_header.h"

int make_num(int * a)
{
    //int deg = a[0] - 1;
    int out = 0;
    for(int i = 1; i <= a[0]; i++){
        out *= 10;
        out += a[i];
    }

    return out;
}

int Step(int l)
{
    int a[l  = 1];
    a[0] = l;
    for(int i = 1; i <= l; i++)
        a[i] = l - i + 1;


    int count = 0;
    while(1){
        int m = l + 1;
        int n;
        int i;
        for(i = a[0] - 1; a[i] < a[i + 1] && i > 0; i--);


        count = make_num(a);
        if(i == 0){
            //printf("%d\n", count);
            if(fast_prime(count)) return count;
            else return -1;
        }
        
        for(int k = i; k <= a[0]; k++){
            if(m < a[k] && a[k] < a[i]){
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
        
        if(fast_prime(count)) return count;
        count = 0;
    }
    
}

int main()
{
    int s = 0;
    for(int i = 10; i > 0; i++){
        s = Step(i);
        if(s != -1){
            printf("%d\n", s);
            return 0;
        }
    }
}