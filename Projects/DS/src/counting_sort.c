
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

int * sort(int * a){

    int l = a[0]; //number of relevant elements

    //maximal element
    int k = -1; 
    for(int i = 1; i <= a[0]; i++){
        if(a[i] > k) k = a[i];
    }

    //minimal element
    int m = k;
    for(int i = 1; i <= a[0]; i++){
        if(a[i] < m) m = a[i];
    }
    m--;

    //fitting everything into [1, something]
    for(int i = 1; i <= a[0]; i++){
        a[i] -= m;
    }

    k -= m;

    //creates the hash-array
    int * temp = calloc(k + 1, sizeof(int));
    //populates it with the number of elements
    for(int i = 1; i <= k; i++){
        temp[a[i]]++;
    }

    // for(int i = 1; i <= k; i++ ){
    //     printf("%d\n", temp[i]);
    // }

    //maps temp back onto a
    int ind = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= temp[i]; j++){
            a[ind] = i;
            ind++;
        }
    }
    free(temp);
    for(int i = 1; i <= 10; i++ ){
        printf("%d\n", a[i]);
    }

    //restores the values of the original array
    for(int i = 1; i <= a[0]; i++){
        a[i] += m;
    }
    return a;
}


int main(){
    int * a = malloc(11 * sizeof(int));
    a[0] = 10;
    for(int i = 1; i <= 10; i++){
        a[i] = 20 - i; 
    }
    printf("Here.\n");
    for(int i = 1; i <= 10; i++ ){
        printf("%d\n", a[i]);
    }
    int * out = sort(a);
    printf("Sorted.\n");

    for(int i = 1; i <= 10; i++ ){
        printf("%d\n", out[i]);
    }

    free(a);

}