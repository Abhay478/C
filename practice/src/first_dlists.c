
#include "my_header.h"

typedef struct dl_node Node;

#define BEGINNING 0
#define END -1
#define DEFAULT 1

bool logic(Node * current, Node * new)
{
    return ((current->sc).i < (new->sc).i && ((current->next)->sc).i > (new->sc).i) ? 1 : 0;
}

Node * form(int n)
{
    Node * new = malloc(sizeof(Node));
    new->sc.i = n;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void insert(Node ** head, int setting, Node * new)
{
    Node * current = *head;
    switch (setting){
        case BEGINNING :
            (*head)->prev = new;
            new->next = *head;
            new->prev = NULL;
            *head = new;
        break;
        case END :
            while(current->next != NULL)
                current = current->next;
            current->next = new;
            new->prev = current;
            new->next = NULL;
        break;
        case DEFAULT : 
            while(current->next != NULL && !logic(current, new))
                current = current->next;

            if(current->next == NULL){
                current->next = new;
                new->prev = current;
                new->next = NULL;
            }
            else{
                current->next->prev = new;
                new->next = current->next;
                current->next = new;
                new->prev = current;
            }
        break;

            
    
        default : printf("Invalid setting.\n");
        break;
    }
}

#define ALL_CASES 2
#define ALL -2

void Remove(Node ** head, int setting, ...)
{
    Node * current = *head;
    int val = 0;
    if(setting == DEFAULT || setting == ALL_CASES){
        va_list ap;
        va_start(ap, setting);
        val = va_arg(ap, int);
        va_end(ap);
    }

    switch(setting){
        case BEGINNING :
            *head = (*head)->next;
            free((*head)->prev);
        break;
        case END :
            while(current->next != NULL)
                current = current->next;
            current->prev->next = NULL;
            free(current);
        break;

        case DEFAULT :
            if((current->sc).i == val){
                *head = (*head)->next;
                free((*head)->prev);
                return;
            }
            while(current->next != NULL){
                if((current->sc).i == val){
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    free(current);
                    return;
                }
                current = current->next;
            }
            if((current->sc).i == val){
                current->prev->next = NULL;
                free(current);
                return;
            }
        break;

        case ALL_CASES :
            if((current->sc).i == val){
                *head = (*head)->next;
                free((*head)->prev);
            }
            while(current->next != NULL){
                if((current->sc).i == val){
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    free(current);
                }
                current = current->next;
            }
            if((current->sc).i == val){
                current->prev->next = NULL;
                free(current);
            }
        break;
        case ALL : 
            while(current != NULL){
                *head = current->next;
                free(current);
                current = *head;
            }
        break;
        default : printf("Invalid setting.\n");
        break;
    }
}

Node * search(Node * head, int n)
{
    Node * current = head;
    while(current != NULL)
        if(current->sc.i == n) break;
    
    return current;
}

void Display(Node * head)
{
    Node * current = head;
    while(current != NULL){
        printf("%d\n", current->sc.i);
        current = current->next;
    }
}

void Sort(Node *)