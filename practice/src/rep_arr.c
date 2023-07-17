
#include "my_header.h"

int * check_rep_s(char * a)
{
    a = InSort(a);
    
    //sorted
    int * Dupl = (int*)calloc(1, sizeof(int));
    int reps = 0;
    int count = 0;
    for(int i = 0; i < strlen(a) - 1; i++){
        if(a[i+1] != a[i]){
            Dupl[count] = i + 1 - reps; 
            reps += i + 1;
            count++;
            Dupl = (int *)realloc(Dupl, (count + 1)*sizeof(int));
        }
    }
    if(reps != 0) return Dupl;
    else return 0;
}

int * check_rep_i(int * a, int l)
{
    a = InSort(a);
    
    //sorted
    int * Dupl = (int*)calloc(1, sizeof(int));
    int reps = 0;
    
    int count = 0;
    for(int i = 0; i < l - 1; i++){
        if(a[i+1] != a[i]){
            Dupl[count] = i + 1 - reps; 
            reps += i + 1;
            count++;
            Dupl = (int *)realloc(Dupl, (count + 1)*sizeof(int));
        }
    }
    if(reps != 0) return Dupl;
    else return 0;
}