
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * format_for_sort(int * a, int n){
    int * out = malloc((n + 2)*sizeof(int));
    int max = -1;
    out[0] = n;
    for(int i = 0; i < n; i++){
        out[i + 1] = a[i];
        if(a[i] > max){
            max = a[i];
        }
    }
    out[n + 1] = max;
    // free(a);
    return out;
}

int * sort(int * a)
{
    int l = a[0]; //number of relevant elements
    int k = a[l + 1]; //upper bound
    int * temp = calloc(k, sizeof(int));
    for(int i = 1; i <= l; i++){
        temp[a[i] - 1]++;
    }
    int ind = 1;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < temp[i]; j++){
            a[ind] = i + 1;
            ind++;
        }
    }
    free(temp);
    return a;
}

int main(){

    int * a = malloc(10000000 * sizeof(int));
    for(int i = 0; i <= 1000000; i++){
        a[i] = 10000000 - i; 
    }
    printf("Here.\n");

    int * out = sort(format_for_sort(a, 10000000));
    printf("Sorted.\n");

    free(a);

    // for(int i = 1; i < 1000001; i++){
    //     printf("%d\n", out[i]);
    // }

}