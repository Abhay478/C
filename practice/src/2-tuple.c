
#include "my_header.h"

void print(int * a, char sep, bool order)
{
    if(order == 0)
        for(int i = 1; i <= a[0]; i++)
            printf("%d%c", a[i], sep);
    else
        for(int i = a[0]; i >= 0; i--)
            printf("%d%c", a[i], sep);

    printf("\n");
}
/*
int * Merge(int * left, int * right)
{
    int m = left[0];
    int n = right[0];
    int l = fmax(m, n);
    int * out = malloc((m + n + 1)*sizeof(int));
    out[0] = m + n;

    int i, j, k;
    for(i = 1, j = 1, k = 1; i <= l; i++)
        if(left[j] < right[k] && j <= m){
            out[i] = left[j];
            j++;
        }
        else if(k <= n){
            out[i] = right[k];
            k++;
        }

    
    
    free(left);
    free(right);
    return out;
}

int * Sort(int * a)
{
    if(a[0] == 1) return a;
    int mid = a[0]/2;
    int * left = calloc(mid + 1, sizeof(int));
    left[0] = mid;
    for(int i = 1; i <= mid; i++)
        left[i] = a[i];

    

    int * right = calloc(a[0] - mid + 1, sizeof(int));
    right[0] = a[0] - mid;
    for(int i = mid + 1; i <= a[0]; i++)
        right[i - mid] = a[i];

    
    left = Sort(left);
    right = Sort(right);

    return Merge(left, right);

}
*/
bool Search(int * a, int x)
{
    int l = 1;
    int h = a[0];
    int mid;
    while(l <= h){
        if(a[l] == x || a[h] == x) return true;
        mid = (l + h)/2;
        if(a[mid] == x) return true;
        else if(a[mid] < x) h = mid - 1;
        else l = mid + 1;
    }
    return false;
}

int comp(const void * a, const void * b)
{
    //return *(int *)a < *(int *)b ? 1 : 0;
    if(*(int *)a == *(int *)b) return 0;
    else if (*(int *)a < *(int *)b) return -1;
    else return 1;

}

bool find(int * a, int x)
{
    bool out = false;

    mergesort(a + 1, a[0], sizeof(int), comp);
    print(a, '\t', 0);
    int * less = malloc(sizeof(int));
    int * more = malloc(sizeof(int));
    less[0] = 0;
    more[0] = 0;
    for(int i = 1; i <= a[0]; i++)
        if(x%2 == 0 && a[i] == x/2 && a[i + 1] == x/2){
            out = true;
            break;
        }
        else if(a[i] < x/2){
            less[0]++;
            less = realloc(less, (less[0] + 1)*sizeof(int));
            less[less[0]] = a[i];
        }
        else if(a[i] > x/2 && a[i] <= x){
            more[0]++;
            more = realloc(more, (more[0] + 1)*sizeof(int));
            more[more[0]] = a[i];
        }

        
    if(out == false)
        for(int i = 1; i <= less[0] && out == false; i++)
            out = Search(more, x - less[i]);
            
        
    
        
    free(less);
    free(more);

    return out;
}

int main()
{
    int arr[] = {7, 23, 4, 7, 12, 9, 0, 33};
    printf("%d\n", find(arr, 32));
}