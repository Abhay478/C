
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int val;
    struct node * next;
    bool stat;

} node;

node * pop(node ** head)
{
    if(*head == NULL) return NULL;

    (*head)->next->stat = 1;
    node * new_head = (*head)->next;
    (*head)->next = NULL;
    printf("Popped : %d\n", (*head)->val);
    free(*head);
    *head = new_head;

    return head;
}

int push(node ** head, int n)
{
    node * new = malloc(sizeof(node));
    new->val = n;
    new->stat = 1;

    if(head == NULL){
        new->next = NULL;
        return 1;
    }

    new->next = *head;
    (*head)->stat = 0;
    *head = new;
    return 0;
}

