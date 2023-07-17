
#include "my_header.h"

//book node
struct bnode{
    char * aname;
    char * bname;
    struct bnode * next;
};

//member node
struct mnode{
    char * mname;
    struct bnode * head;
    struct mnode * next;
};

//used for insertion, hence presorted list obtained.
bool mlogic(struct mnode * mem, char * s)
{
    if(mem->next == NULL) return true;
    if(strcmp(mem->mname, s) <= 0 && strcmp((mem->next)->mname, s) >= 0) return true;
    else return false;
}

//use for sorting only
bool blogic(struct bnode * bk1, struct bnode * bk2)
{
    if(bk1->next == NULL) 
        return true;
    
    if(strcmp(bk1->aname, bk2->aname) < 0 && strcmp((bk1->next)->aname, bk2->aname) > 0) 
        return true;
    else if(strcmp(bk1->aname, bk2->aname) == 0 && strcmp(bk1->bname, bk2->bname) < 0 && strcmp((bk1->next)->bname, bk2->bname) > 0) 
        return true;
    else 
        return false;
}

void Archive(struct mnode * head)
{
    FILE * f = fopen("Archive.txt",  "w+");
    if(f == NULL) printf("Archive Unsuccessful.\n");

    struct mnode * mcurrent = head;
    struct bnode * bcurrent = head->head;
    while(mcurrent != NULL){
        fprintf(f, "%s\nBooks : \n", mcurrent->mname);
        bcurrent = mcurrent->head;
        while(bcurrent != NULL){
            fprintf(f, "%s | %s\n", bcurrent->bname,  bcurrent->aname);
            bcurrent = bcurrent->next;
        }
        fprintf(f, "\n\n\n");
        mcurrent = mcurrent->next;
    }
    fclose(f);
}

struct bnode * Asearch(struct bnode * head, char * name)
{
    struct bnode * current = head;
    if(current->aname == name){
        struct bnode * dummy = calloc(1, sizeof(struct bnode));
        if(dummy == NULL) return NULL;
        dummy->next = current;
        return dummy;
    }
    while(current->next != NULL)
        if((current->next)->aname == name) 
            return current;

    return NULL;
}

struct bnode * Bsearch(struct bnode * head, char * name)
{
    struct bnode * current = head;
    if(current->bname == name){
        struct bnode * dummy = calloc(1, sizeof(struct bnode));
        if(dummy == NULL) return NULL;
        dummy->next = current;
        return dummy;
    }
    while(current->next != NULL)
        if((current->next)->bname == name) 
            return current;

    return NULL;
}

struct mnode * Msearch(struct mnode * head, char * name)
{
    struct mnode * current = head;
    if(current->mname == name){
        struct mnode * dummy = calloc(1, sizeof(struct mnode));
        if(dummy == NULL) return NULL;
        dummy->next = current;
        dummy->head = NULL;
        return dummy;
    }
    while(current->next != NULL)
        if((current->next)->mname == name) 
            return current;

    return NULL;
}

int minsert(struct mnode ** head, struct mnode * new)
{
    struct mnode * current = *head;
    if(new == NULL) return -1;
    

    while (current != NULL){
        if(mlogic(current, new->mname)){
            struct mnode * prev = current->next;                 //saves the address of the old next node
            current->next = new;                                //sets next node to new
            new->next = prev;                                   //node after that set to old next node.
            return 0;
        }
        current = current->next;    
    }  
    if(current->next == NULL) current->next = new;
    new->next = NULL;
    return 0;
}

struct bnode * bform(char * aname, char * bname)
{
    struct bnode * book = calloc(1, sizeof(struct bnode));
    if(book == NULL) return NULL;
    book->aname = aname;
    book->bname = bname;
    book->next = NULL;
    return book;
}

struct mnode * mform(char * name)
{
    struct mnode * mem = calloc(1, sizeof(struct mnode));
    if(mem == NULL) return NULL;
    mem->head = calloc(1, sizeof(struct bnode));
    mem->mname = name;
    mem->next = NULL;

    return mem;
}

void wipe(struct bnode * head) 
{
    struct bnode * current = head;
    struct bnode * tmp = head->next;
    if(tmp == NULL){
        free(head);
        return;
    }
    head = NULL;
    while(current->next != NULL){
        free(current);
        current = tmp;
        tmp = current->next;
    }    
    free(current);
}

int mdelete(struct mnode ** head, char * name)
{
    struct mnode * current = *head;

    struct mnode * req = Msearch(*head, name);
    if(req == NULL) return -1;
    struct mnode * tmp = req->next;
    wipe(tmp->head);
    if(tmp == *head){ 
        *head = tmp->next;
        free(tmp);
        free(req); //used to be dummy
        return 0;
    }
    req->next = tmp->next;
    free(tmp);

    return 0;    
}

int Borrow(struct mnode * head, char * name, struct bnode * b)
{
    struct mnode * preq = Msearch(head, name);
    if(preq == NULL) return -1;
    struct mnode * req = preq->next;
    b->next = req->head;
    req->head = b;
    return 0;
}

int Return(struct mnode * head, char * mname, char * bname)
{
    struct mnode * preq = Msearch(head, mname);
    if(preq == NULL) return -1;
    struct mnode * req = preq->next;
    struct mnode * current = head;

    struct bnode * bkp = Bsearch(req->head, bname);
    if(bkp == NULL) return -1;
    struct bnode * tmp = bkp->next;
    if(tmp == req->head) 
        req->head = tmp->next;
    bkp->next = tmp->next;
    free(tmp);
    bkp->next = NULL;
    return 0;
}

void Display(struct mnode * head)
{
    struct mnode * current = head;
    while(current != NULL){
        struct bnode * bcu = current->head;
        printf("%s :  \n", current->mname);
        while(bcu != NULL){
            printf("%s %s\n", bcu->aname, bcu->bname);
            bcu = bcu->next;
        }
        printf("\n\n\n");
        current = current->next;
    }
}

int main()
{    
    struct mnode * head = calloc(1, sizeof(struct mnode));
    head->mname = "ABC";
    head->head = NULL;
    struct mnode * new = mform("XYZ");

    minsert(&head, new);
    
    Borrow(head, "XYZ", bform("B", "Book 2"));
    
    Borrow(head, "ABC", bform("B", "Book 2"));
    
    Borrow(head, "XYZ", bform("A", "Book 1"));
    
    Return(head, "XYZ", "Book 2");
    Display(head);
    mdelete(&head, "ABC");
    Display(head);
    
    Archive(head);
}

