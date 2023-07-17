
#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int n;
    struct n * next;
} node;

node * reverse(node * head)
{
    node * last = head;
    while(last->next != NULL){
        last = last->next;
    }
    //no more changing last
    node * current = head;
    head = head->next;
    last->next = current;
    current->next = NULL;

    node * other = head;
    //now to iterate
    while(head != last){
        head = head->next;
        other->next = current;
        last->next = other;
        current = other;
        other = head;
    }

    return last;
}

node * make_ll(int * a)
{
    node * head = malloc(sizeof(node));
    node * current = head;
    for(int i = 0; i < a[0] - 1; i++){
        current->n = a[i + 1];
        current->next = malloc(sizeof(node));
        current = current->next; 
    }
    current->n = a[a[0]];
    return head;
}

node * frame_rev(node * head)
{
    node * left = head;
    node * middle = head->next;
    node * right = middle->next;
    head->next = NULL;
    while(right != NULL){
        middle->next = left;
        left = middle;
        middle = right;
        right = right->next;
    }

    middle->next = left;
    return middle;
}

int main(){
    int * a = malloc(10000001 * sizeof(int));
    a[0] = 10000000;
    for(int i = 1; i < 10000001; i++){
        a[i] = i;
    }

    node * head = make_ll(a);
    head = frame_rev(head);

    // while(head != NULL){
    //     printf("%d\n", head->n);
    //     head = head->next;
    // }

    printf("r");

    head = make_ll(a);
    head = reverse(head);

    printf("r");

    // while(head != NULL){
    //     printf("%d\n", head->n);
    //     head = head->next;
    // }
    return 0;
    
}