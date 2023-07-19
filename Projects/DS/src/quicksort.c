
#include <stdio.h>
#include <stdlib.h>

int random_in(int m, int n)
{
    int a = random();
    if(n < m) return m;
    int diff = n - m + 1;
    a %= diff;
    a += m;

    return a;
}

int bifurcate(int ** a, int m, int n)
{
    int temp;

    // int k = random_in(m, n);
    // temp = (*a)[k];
    // (*a)[k] = (*a)[n];
    // (*a)[n] = temp;

    
    int x = (*a)[n];
    int i = m - 1;
    for(int j = m; j < n; j++){
        if((*a)[j] <= (*a)[x]){
            i++;
            temp = (*a)[i];
            (*a)[i] = (*a)[j];
            (*a)[j] = temp;
        }
    }
    temp = (*a)[i + 1];
    (*a)[i + 1] = (*a)[n];
    (*a)[n] = temp;

    return i + 1;
}

int hoare(int ** a, int m, int n)
{
    int x = (*a)[m];
    int i = m - 1;
    int j = n + 1;
    while(1){
        while((*a)[j] > x) j--;
        while((*a)[i] < x) i++;
        if(i < j){
            int temp = (*a)[i];
            (*a)[i] = (*a)[j];
            (*a)[j] = temp;
        }
        else return j;
    }
}
void quicksort(int ** a, int m, int n)
{
    
    int l;
    if(m < n){
        // if(m + 1 == n) return;
        l = bifurcate(a, m, n);
        quicksort(a, m, l - 1);
        quicksort(a, l + 1, n);
    }
}


int main()
{
    int * a = malloc(7 * sizeof(int));
    a[0] = 6;
    for(int i = 1; i <= a[0]; i++)
        scanf("%d", a + i);
    
    // for(int i = 1; i <= a[0]; i++)
    //     printf("%d ", a[i]);

    quicksort(&a, 1, a[0]);
    // printf("Sorted\n");

    for(int i = 1; i <= a[0]; i++)
        printf("%d\n", a[i]);

    return 0;

    // for(int i = 0; i < 100; i++){
    //     printf("%d\n", random_in(i, 99));
    // }
}