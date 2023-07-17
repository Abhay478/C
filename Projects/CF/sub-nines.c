
#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 0;
    scanf("%d", &N);
    
    int n;

    for(int q = 0; q < N; q++){
        scanf("%d", &n);
        char * in = malloc(n*sizeof(char));
        scanf("%s", in);
        for(int i = 0; i < n; i++)
            in[i] = '9' - in[i] + '0';

        if(in[0] == '0'){
            in[0] = '1';
            in[n - 1] = (in[n - 1] - '0' + 2) % 10 + '0';
            int i;
            if(in[n - 1] < '2')
                for(i = n - 2; in[i] == '9'; i--)
                    in[i] = '0';
            
            in[i] += 1;
        }
        printf("%s\n", in);
        free(in);
    }
    
    return 0;
}