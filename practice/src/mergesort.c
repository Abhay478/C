
#include "my_header.h"

typedef struct sl_node node;
typedef struct dl_node Node;

node * merge(node * left, node * right)
{
    node * head = malloc(sizeof(node));
    node * current = head;

    while(left != NULL && right != NULL){
        if(left->sc.i < right->sc.i){
            current->next = left;
            left = left->next;
        }
        else{
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }
    while(left != NULL){
        current->next = left;
        left = left->next;
        current = current->next;
    }
    while(right != NULL){
        current->next = right;
        right = right->next;
        current = current->next;
    }

    return head->next;
}

node * sort(node * head)
{
    node * current = head;
    node * half = malloc(sizeof(node));
    half->next = head;
    int i;
    for(i = 0; current != NULL; i++){
        current = current->next;
        if(i%2 == 1) half = half->next;
    }
    if(i == 0) return NULL;
    if(i == 1) return head;
    if(i == 2){
        if(head->sc.i < head->next->sc.i) return head;
        else{
            current = head;
            current->next->next = current;
            head = current->next;
            current->next = NULL;
            return head;
        }
    }
        
    

    node * left = head;
    node * right = half->next;
    half->next = NULL;

    left = sort(left);
    right = sort(right);

    return merge(left, right);
}


Node * Merge(Node * left, Node * right)
{
    Node * head = malloc(sizeof(Node));
    Node * current = head;

    while(left != NULL && right != NULL){
        if((left->sc).i < (right->sc).i){
            current->next = left;
            left->prev = current;
            left = left->next;
        }
        else{
            current->next = right;
            right->prev = current;
            right = right->next;
        }
        current = current->next;
    }
    while(left != NULL){
        current->next = left;
        left->prev = current;
        left = left->next;
        current = current->next;
    }
    while(right != NULL){
        current->next = right;
        right->prev = current;
        right = right->next;
        current = current->next;
    }
    Node * out = head->next;
    free(head);
    return out;
}

Node * Sort(Node * head)
{
    Node * current = head;
    Node * half = malloc(sizeof(Node));
    half->next = head;
    int i;
    for(i = 0; current != NULL; i++){
        current = current->next;
        if(i%2 == 1) half = half->next;
    }
    if(i == 0) return NULL;
    if(i == 1) return head;
    if(i == 2){
        if(head->sc.i < head->next->sc.i) return head;
        else{
            current = head;
            current->next->next = current;
            head = current->next;
            current->next = NULL;
            return head;
        }
    }
        
    

    Node * left = head;
    Node * right = half->next;
    half->next->prev = NULL;
    half->next = NULL;

    left = Sort(left);
    right = Sort(right);

    return Merge(left, right);
}

void d_InSort(Node * head)
{
    Node * current = head;
    Node * move = current;

    Node * dummy = malloc(sizeof(Node));
    dummy->next = head;
    head->prev = dummy;
    Node * p;

    while(current != NULL){
        move = current;
        current = current->next;
        p = current->prev;
        move->prev->next = move->next;
        move->next->prev = move->prev;
        while(move != dummy && move->sc.i > p->sc.i)
            p = p->prev;
        
        p->next->prev = move;
        move->next = p->next;
        p->next = move;
        move->prev = p;
        
    }
}