
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

struct word{
    char * s;
    int c;
    struct word * next;
};

struct word * merge(struct word * left, struct word * right)
{ 
    struct word * result = calloc(1, sizeof(struct word));
    struct word * current = result;

    while(left != NULL && right != NULL){
        if (left->c >= right->c){
            current->next = left;
            left = left->next;
        }
        else{
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    while (left != NULL){
        current->next = left;
        left = left->next;
        current = current->next;
    }
            
    while (right != NULL){
        current->next = right;
        right = right->next;
        current = current->next;
    }
    
    return result->next;
}

struct word * merge_sort(struct word * head) 
{
    int m = 0;
    struct word * current = head;

    while (current->next != NULL){
        m++;
        current = current->next;
    }

    if(m < 2) 
        return head;
    
    struct word * left = head;
    current = head;
    for(int i = 1; i < m/2; i++)
        current = current->next;

    struct word * right;
    right = current->next;
    current->next = NULL;
    
    left = merge_sort(left);
    right = merge_sort(right);

    
    return merge(left, right);
}


struct word * formlist(FILE * f, struct word * head)
{
    int x = 0;
    int count = 0;
    
    head->s = "";
    head->c = 0;
    head->next = NULL;
    struct word * current = head;
    while((x = getc(f)) != EOF){
        ungetc(x, f);
        char * w = (char *)malloc(1);
        
        while(isalpha(x = getc(f))){
            w = realloc(w, sizeof(char)*strlen(w) + 2);
            strcat(w, &x);
        }
        count++;
        
        for(current = head; ; current = current->next){
            if(!strcasecmp(w, current->s)){
                (current->c)++;
                break;
            }
            

            if(!strcmp(current->s, "")){
                struct word * new = calloc(1, sizeof(struct word));
                new->next = NULL;
                new->c = 0;
                new->s = "";

                current->s = w;
                current->c = 1;
                current->next = new;   
                break;
            }
            
        }
        
        w = "";
        
        
    }

    head = merge_sort(head);
    return head;
}

int main()
{
    FILE * f = fopen("Doc.txt", "r");
    struct word * head = calloc(1, sizeof(struct word));
    head = formlist(f, head);
    
    struct word * current = head;
    while(current != NULL){
        printf("%s : %d\n",  current->s, current->c);
        current = current->next;
    }

    while(current != NULL){
        current = head;
        head = current->next;
        free(current);
    }

    fclose(f);
    return 0;
}