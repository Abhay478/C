
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int getln(FILE * f)
{
    long int off = ftell(f);
    fseek(f, 0, SEEK_SET);
    long int count = 1;
    for(long int i = 0; i < off; i++)
        if(getc(f) == '\n')
            count++;
    fseek(f, off, SEEK_SET);
    return count;
}

struct line{
    int ln;
    struct line * next;
};
struct word{
    char * s;
    struct line * head;
    struct word * next;
};

void insert(struct line * head, int num)
{
    struct line * new = malloc(sizeof(struct line));
    new->ln = num;
    new->next = NULL;
    if(head->ln == 0){
        head = new;
        return;
    }
    struct line * current = head;
    while(current->next != NULL)
        current = current->next;

    current->next = new;
}

bool noise(char * s)
{
    char * s1 = malloc(31*sizeof(char));

    FILE * fp = fopen("Common_Words.txt",  "r");
    while(fscanf(fp, "%s", s1) != -1)
        if(!strcasecmp(s, s1)){
            fclose(fp);
            free(s1);
            return true;
        }

    fclose(fp);
    free(s1);
    return false;
    
}

void form(struct word * head, FILE * f)
{
    char * w = (char *)malloc(sizeof(char));
    int x;
    struct word * current = head;

    head->s = "";
    head->head = malloc(sizeof(struct line));
    head->head->ln = 0;
    head->head->next = NULL;
    head->next = NULL;
    
    while((x = getc(f)) != EOF){
        ungetc(x, f);
        char * w = (char *)malloc(1);
        
        while(isalpha(x = getc(f))){
            w = realloc(w, sizeof(char)*strlen(w) + 2);
            strcat(w, &x);
        }
        if(noise(w)) continue;
        
        for(current = head; ; current = current->next){
            if(!strcasecmp(w, current->s)){
                insert(current->head, getln(f));
                break;
            }
            
            if(!strcmp(current->s, "")){
                struct word * new = calloc(1, sizeof(struct word));
                new->next = NULL;
                new->s = "";
                new->head = malloc(sizeof(struct line));
                new->head->ln = 0;
                new->head->next = NULL;


                current->s = w;
                insert(current->head, getln(f));
                current->next = new;   
                break;
            }
            
        }
        
        w = "";
        
        
    }

    
}


void Display(struct line * head){
    struct line * current = head;
    while(current != NULL){
        printf("%d ", current->ln);
        current = current->next;
    }  

    printf("\n");
} 

int main(){
    FILE * f = fopen("Doc.txt",  "r");
    struct word * head = malloc(sizeof(struct word));
    struct word * current = head;

    form(head, f);

    while(current != NULL){
        printf("%s : ",  current->s);
        Display(current->head);
        current = current->next;
    }
    struct line * lcurrent;
    while(current != NULL){
        current = head;
        head = current->next;

        while(lcurrent != NULL){
            lcurrent = current->head;
            current->head = lcurrent->next;
            free(lcurrent);
        }

        free(current);
    }


    
    fclose(f);
    return 0;
}