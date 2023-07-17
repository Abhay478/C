
#include "my_header.h"

/*
typedef struct s{
    L x;
    L y;
    struct s * next;
    struct s * prev;
} point;

typedef struct {
    int n;
    point * next;
} Head;

L dist(point * a, point * b)
{
    return sqrt(pow(a->x - b->x, 2), pow(a->y - b->y, 2));
}

L strip_find(Head * head)
{
    
}

L find(Head * head)
{
    if(head->n == 2) return dist(head->next, head->next->next);
    point * first = head->next;
    point * current = first;
    int i;
    for(i = 1; i <= (head->n)/2; i++)
        current = current->next;

    Head * rhead = malloc(sizeof(Head));
    rhead->n = head->n - i;
    rhead->next = current->next;
    //current->next = NULL;

    Head * lhead = malloc(sizeof(Head));
    lhead->n = i;
    lhead->next = head->next;

    L lmin = find(lhead);
    L rmin = find(rhead);
    L min = fmin(lmin, rmin);

    L smin = strip_find(head);

    return fmin(smin, min);
}*/

typedef struct {
    int x, y;
} point;

typedef struct g{
    int x, y;
    struct g * lp;
    struct g * rp;
} Point;

typedef union n{
    Point * root;
    point * first;
} Next;

typedef struct c{
    int n;
    Next * p;
} Cap;

Cap * treefy(Cap * a)
{
    Cap * out = malloc(sizeof(Cap));
    out->p->root = malloc(sizeof(Point));
    int l = a->n;
    out->n = l;
      

}