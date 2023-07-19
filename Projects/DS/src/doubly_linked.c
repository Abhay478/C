#include <stdio.h>
#include <stdlib.h>

typedef struct dl{
    int n;
    struct dl * next;
    struct dl * prev;
} node;

void disp(node * head)
{
    node * current = head;
    while(current != NULL){
        printf("%d ", current->n);
        current = current->next;
    }
    printf("\n");
}

node * make(int v)
{
    node * out = calloc(1, sizeof(node));
    out->n = v;

    return out;
}

node * trav(node * head, int n)
{
    node * out = head;
    for(int i = 1; i < n && out != NULL; i++) out = out->next;

    return out;
}

void insert(node * n1, node * n2)
{
    if(n1->prev != NULL) n1->prev->next = n2;

    n2->prev->next = n2->next;

    if(n2->next != NULL) n2->next->prev = n2->prev;

    n2->prev = n1->prev;
    n1->prev = n2;
    n2->next = n1;

}

node * right(node * head, int a, int b){
    int head_change = 0;

    node * n1 = trav(head, a);
    if(n1 == NULL) return NULL;

    node * n2 = trav(head, b);
    if(n2 == NULL) return NULL;

    if(n1 == head){
        head->prev = make(0);
        head->prev->next = head;
        head = head->prev;
        head_change = 1;
    }

    insert(n1, n2);

    if(head_change) head = head->next;

    return head;
}

node * reverse(node * head, int a, int b)
{
    int head_change = 0;
    node * n1 = trav(head, a);
    if(n1 == NULL) return NULL;
    

    node * n2 = trav(head, b);
    if(n2 == NULL) return NULL;

    if(n1 == head){
        head->prev = make(0);
        head->prev->next = head;
        head = head->prev;
        head_change = 1;
    }

    node * last = n2;

    while(n1 != last){
        last = n2->prev;
        insert(n1, n2);
        n2 = last;
    }

    if(head_change) head = head->next;
    return head;
}

node * form(int * a)
{
    node * head = make(0);
    node * new = head;

    for(int i = 1; i <= a[0]; i++){
        new->n = a[i];
        new->next = make(0);
        new->next->prev = new;
        new = new->next;
    }
    new->prev->next = NULL;
    free(new);

    return head;
}

int main()
{
    int a[] = {5, 1, 2, 3, 4, 5};
    node * head = form(a);
    head = right(head, 2, 5);
    disp(head);

    return 0;
}