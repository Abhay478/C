
#include "my_header.h"



#define BEGINNING 0
#define END -1
#define DEFAULT 1



node * sform(int n)
{
    node * new = malloc(sizeof(node));
    new->sc.i = n;
    new->next = NULL;
    return new;
}

void s_insert(node ** head, int setting, node * new)
{    
    node * current = *head;

    if(setting == BEGINNING){
        new->next = *head;
        *head = new;
        
    }
    else if(setting == END){
        while (current->next != NULL)
            current = current->next;
        current->next = new;
        new->next = NULL;    
    }
    else if(setting == DEFAULT){
        while (current->next != NULL){
            if(new->sc.i <= current->next->sc.i){
                node * prev = current->next;                 //saves the address of the old next node
                current->next = new;                                //sets next node to new
                new->next = prev;                                   //node after that set to old next node.
                return;
            }
            current = current->next;    
        }  
    }
    else perror("Invalid setting.\n");
    return;
}

node * s_Search(node * head, int n)
{
    node * current = head;
    while(current != NULL){
        if(n == current->sc.i) return current;
        current = current->next;
    }
    return NULL;
}

#define ALL_CASES 2
#define ALL -2

void Remove(node ** head, int setting, ...)
{
    node * current = *head;
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
            free(current);
        break;
        case END :
            while(current->next->next != NULL)
                current = current->next;
            free(current->next);
        break;

        case DEFAULT :
            if((current->sc).i == val){
                *head = (*head)->next;
                free(current);
                return;
            }
            while(current->next->next != NULL){
                if((current->next->sc).i == val){
                    current->next = current->next->next;
                    free(current->next);
                    return;
                }
                current = current->next;
            }
            if((current->next->sc).i == val){
                free(current->next);
                return;
            }
        break;

        case ALL_CASES :
            if((current->sc).i == val){
                *head = (*head)->next;
                free(current);
            }
            while(current->next != NULL){
                if((current->next->sc).i == val){
                    current->next = current->next->next;
                    free(current->next);
                }
                current = current->next;
            }
            if((current->next->sc).i == val){
                free(current->next);
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




        
