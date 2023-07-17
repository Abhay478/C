
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(){
    int *p_dyn = (int *)malloc(15*sizeof(int));
    if(!p_dyn){
        return 1;
    }
    printf("Enter fifteen numbers.");
    for(int i = 0; i<15; i++){
        scanf("%d", p_dyn++);
    }
    p_dyn -= 14;
    for(int i = 0; i< 15; i++){
        printf("%d @ %p\n", *p_dyn, p_dyn++);
    }
    free(p_dyn);

    return 0;
}