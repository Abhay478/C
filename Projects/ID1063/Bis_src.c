/*
5th Jan, 2022
Problem 3

Roll Number:Abhay Shankar K
Name: cs21btech11001

*/

#include <stdio.h>


/* Returns 1 if 'search' is in arr, 0 otherwise
arr is an array of n integers assumed to be in descending order. */
int bisectionSearch(int n, int arr[], int search) 
{
    int l = 0, h = n - 1, mid;
    while(l<h){
        if(arr[l] == search || arr[h] == search)
            return 1;
        mid = (l + h)/2;
        if(arr[mid] == search)
            return 1;
        else if(arr[mid] < search)
            h = mid - 1;
        else if(arr[mid] > search)
            l = mid + 1;
    }
    return 0;
}

int main() {
    int n, element, search;
    int numbers[50];

    while (scanf("%d", &n) != -1) {
        for(int i = 0; i < n; i = i+1) {
            scanf("%d", &numbers[i]);
        }
        scanf("%d", &search);
        printf("%d\n", bisectionSearch(n, numbers, search));
    }
    return 0;
}
