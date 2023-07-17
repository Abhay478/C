
#include "my_header.h"

struct Vertex;
struct Edge;

struct Vertex{
    int least;
    int n;
    struct Edge ** E;
    struct Vertex * next;
};

struct Edge{
    int dist;
    struct Vertex * next;
};
typedef struct Vertex vert;
typedef struct Edge edge;


void set_least(vert * head)
{
    vert * current = head;
    while(current != NULL){
        for(int i = 0; i < current->n; i++){
            if((current->E)[i]->next->least == 0 || (current->E)[i]->next->least < (current->E)[i]->dist + current->least) 
                (current->E)[i]->next->least = (current->E)[i]->dist + current->least;
        }
        current = current->next;
    }
}

vert * initialize(int ** a)
{
    vert * head = malloc(sizeof(vert));
    head->least = 0;
    head->n = 0;
    head->E = malloc(sizeof(edge));
    head->next = NULL;
    vert * current = head;
    for(int i = 1; i < a[0][0]; i++)
    {
        vert * new = malloc(sizeof(vert));
        new->least = 0;
        new->n = 0;
        new->E = malloc(sizeof(edge));
        new->next = NULL;

        current->next = new;
        current = current->next;
    }
    return head;
}

void get_edges(vert * head, int ** a)
{
    vert * current = head;
    vert * dest = head;
    int m = 0;
    for(int i = 1; i <= a[0][0]; i++){
        dest = head;
        for(int j = 0; j < a[0][0]; j++){
            if(a[i][j] != 0){
                current->E[current->n]->next = dest;
                current->E[current->n]->dist = a[i][j];
                (current->n)++;
                current->E = realloc(current->E, (current->n + 1)*sizeof(edge *));
                current->E[current->n] = malloc(sizeof(edge));
            }
            dest = dest->next;
        }
        current = current->next;
    }
}

