
#include <stdio.h>
#include <stdlib.h>


int move(char * a, int n, int k)
{
    for(int i = n - 1; i >= 0; i--){
        if(a[i] == '1'){
            if(n - i - 1 <= k){
                a[n - 1] = '1';
                a[i] = '0';
                k -= n - i - 1;
            }
            break;
        }
    }

    //printf("%s\n", a);

    if(k != 0){
        for(int i = 0; i < n - 1; i++){
            if(a[i] == '1'){
                if(i <= k){
                    a[i] = '0';
                    a[0] = '1';
                    k -= i;
                }
                break;
            }
        }   
    }
    //printf("%s\n", a);

    int sum = 0;
    if(a[0] == '1') sum += 10;
    if(a[n - 1] == '1') sum++;

    for(int i = 1; i < n - 1; i++)
        if(a[i] == '1') sum += 11;
    
    return sum;
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    
    int n;
    int k;
    char * a;

    for(int q = 0; q < N; q++){
        scanf("%d", &n);
        scanf("%d", &k);
        a = malloc(n * sizeof(char));

        scanf("%s", a);
        
        printf("%d\n", move(a, n, k));
        
        free(a);
    }
    
    return 0;
}