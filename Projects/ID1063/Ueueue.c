/*
Name : Abhay Shankar K
Roll no. : cs21btech11001

Date : Feb 25.
*/
#include <stdio.h>
#include <stdlib.h>

int q_len = 0;

typedef struct qnode{
    int val;
    struct qnode * next;
} node;

//takes an integer argument and returns pointer to node containing that integer.
node * form(int n)
{
    node * new = (node *)malloc(sizeof(node));
    if(new == NULL) return NULL;

    new->val = n;
    new->next = NULL;

    return new;
}

//enqueues node containing n onto q(ue)^2.
void nq(node ** tail, int n)
{
    node * new = form(n);
    if(new == NULL) return;
    q_len = q_len + 1;
    if(*tail == NULL){
        *tail = new;
        return;
    }
    (*tail)->next = new;
    (*tail) = new;
    
}

//dequeues first node in queue. returns value of dequeued node or -1 if dequeue was requested on an empty queue.
int dq(node ** head)
{
    if(*head == NULL || q_len <= 0){
        return -1;
    }
     
    int ret = (*head)->val;
    node * tmp = *head;
    *head = (*head)->next;
    
    tmp->next = NULL;
    if(tmp != NULL) free(tmp);
    q_len = q_len - 1;
    return ret;

}

int main()
{
    int content = 0;
    int command;
    node * head = NULL;
    node * tail = NULL;
    while((command = getchar()) != EOF){
        switch(command){
            case 'E' :
                scanf("%d", &content);
                
                nq(&tail, content);
                if(head == NULL) head = tail;
            break;

            case 'D' :
                content = dq(&head);
                switch(content){
                    case -1 : printf("Empty\n");
                    break;
                    default : printf("%d\n", content);
                    break;
                }
            break;

            default : break;
        }
    }

    return 0;
}
