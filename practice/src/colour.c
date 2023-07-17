
#include "my_header.h"

struct v;
struct c;
struct e;

typedef struct v{
    int col;
    struct c * cp;
} vert;

typedef struct c{
    int n;
    vert ** list;
} cap;

cap * get_edges(int ** a)
{
    int l = (a[0] - a[1])/sizeof(int);
    vert ** arr = malloc(l*sizeof(vert *));
    for(int i = 0; i < l; i++){
        arr[i] = malloc(sizeof(vert));
        arr[i]->col = -1;
        arr[i]->cp = malloc(sizeof(cap)); 
        arr[i]->cp->n = 0;
        arr[i]->cp->list = malloc(1);
    }
    
    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++){
            if(a[i][j] == 1){
                arr[i]->cp->list = realloc(arr[i]->cp->list, (arr[i]->cp->n + 1)*sizeof(vert *));
                arr[i]->cp->list[arr[i]->cp->n] = arr[j];
                arr[i]->cp->n++;
            }
        }
        arr[i]->cp->n++;
    }
    cap * out = malloc(sizeof(cap));
    out->n = l;
    out->list = arr;
    return out;
}

int colour(cap * a)
{
    int min = 0;
    for(int i = 0; i < a->n; i++){
        min = 0;
        for(int j = 0; j < a->list[i]->cp->n; j++){
            if(a->list[i]->cp->list[j]->col >= min) min = a->list[i]->cp->list[j]->col + 1;
        }
        a->list[i]->col = min;
    }

}

