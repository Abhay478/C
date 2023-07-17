
#include <stdio.h>

void sort(int a[]);
//void search(int arr[]);

int main(){
    printf("Enter ten numbers.\n");
    int arr[10];
    for(int i = 0; i<10; ++i){
        scanf("%d", &arr[i]);
    }
    sort(arr);
    for(int j = 0; j<10; j++){
        printf("%d . %d\n", j+1, arr[j]);
    }
    return 0;
}

void sort(int a[]){
    int m, n, temp;
    for(int i = 0; i< 10; i++){
        m = a[i];
        for(int j = i; j<10; j++){
            if(a[j]<m){
                m = a[j];
                n = j;
            }
        }
        temp = a[i];
        a[i] = a[n];
        a[n] = temp;
    }
}
