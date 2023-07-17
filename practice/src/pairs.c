
#include "my_header.h"

int main()
{
    int * arr = NULL;
    printf("Enter array. Enter -1 to terminate.\n");
    int l = ialloc(&arr, stdin, -1);
    int sum = 0;
    

    for(int i = 0; i < l; i++)
        printf("%d\n", arr[i]);

    printf("\n\n\n\n\n\n");

    for(int i = 0; i < l; i++){
        for(int j = i + 1; j < l; j++){
            sum += arr[i]*arr[j];
        }
    }

    printf("%d\n",sum);
    return 0;
            
}