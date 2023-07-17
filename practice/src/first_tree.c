
#include "my_header.h"

bool is_leaf(NODE * current)
{
    return (current == NULL || (current->lp == NULL && current->rp == NULL)) ? true : false;
}

NODE * tform(int n)
{
    NODE * new = malloc(sizeof(NODE));
    new->sc = calloc(1, sizeof(int));
    (new->sc)->i = n;
    new->lp = NULL;
    new->rp = NULL;
    new->parent = NULL;
    return new;
}

void t_insert(NODE * const root, NODE * new)
{
    if(new == NULL || new->sc == NULL || root->sc == NULL || root == NULL) return;
    if(new->sc->i == root->sc->i){
        free(new->sc);
        new->sc = NULL;
        free(new);
        new = NULL;
        return;
    }
    if(new == NULL || new->sc == NULL || root->sc == NULL || root == NULL) return;
    if(new->sc->i < root->sc->i){
        if(root->lp == NULL){
            root->lp = new;
            new->parent = root;
            return;
        } 
        insert(root->lp, new);
    }
    if(new == NULL || new->sc == NULL || root->sc == NULL || root == NULL) return;
    if(new->sc->i > root->sc->i){
        if(root->rp == NULL){
            root->rp = new;
            new->parent = root;
            return;
        } 
        insert(root->rp, new);
    }
}

NODE * search(NODE * root, int n)
{
    static NODE * ret = NULL;
    if(root == NULL) return NULL;
    if(n == root->sc->i){
        ret = root;
        return ret;
    }
    else if(n < root->sc->i) search(root->lp, n);
    else if(n > root->sc->i) search(root->rp, n);
    
    return ret;
}

void insert_tree(NODE * const root, NODE * new_root)
{
    insert(root, new_root);

    if(is_leaf(new_root)) return;
    
    insert_tree(root, new_root->lp);
    insert_tree(root, new_root->rp);

}

void insert_list(NODE * root, Node * head){
    Node * current = head;
    while(current != NULL){
        insert(root, tform(current->sc.i));
        current = current->next;
        free(current->prev);
    }
}


NODE * copy(NODE * root)
{
    if(root == NULL) return NULL;
    NODE * new_root = tform(root->sc->i);
    new_root->lp = copy(root->lp);
    new_root->rp = copy(root->rp);
    return new_root;
}

void wipe(NODE * root)
{
    if(root == NULL) return;
    if(root->parent != NULL){
        (root == root->parent->lp)? (root->parent->lp = NULL) : (root->parent->rp = NULL);
        root->parent = NULL;
    }

    wipe(root->lp);
    wipe(root->rp);

    
    root->lp = NULL;
    root->rp = NULL;
    free(root->sc);
    root->sc = NULL;
    free(root);
    root = NULL;
}


/*NODE * delete(NODE * root, int n)
{
    NODE * new_root;
    NODE * req = search(root, n);
    if(root == req){
        new_root = copy(root->lp);
        NODE * right = copy(root->rp);
        wipe(root);

        insert_tree(new_root, right);
        return new_root;
    }
    else{
        new_root = copy(req);
        wipe(req);
        insert_tree(root, new_root);
        return root;
    }
}*/

#define IN_ORDER 0
#define PRE_ORDER 1
#define POST_ORDER -1

void Display(NODE * root, int setting, FILE * f)
{
    if(is_leaf(root)){
        if(root->sc != NULL) printf("%d\n", root->sc->i);
        return;
    }

    switch(setting){
        case IN_ORDER : 
            if(root->lp != NULL) Display(root->lp, setting, f);
            if(root->sc != NULL) fprintf(f, "%d\n", root->sc->i);
            if(root->rp != NULL) Display(root->rp, setting, f);
        break;
        case PRE_ORDER :
            if(root->sc != NULL) fprintf(f, "%d\n", root->sc->i);
            if(root->lp != NULL) Display(root->lp, setting, f);
            if(root->rp != NULL) Display(root->rp, setting, f);
        break;
        case POST_ORDER :
            if(root->lp != NULL) Display(root->lp, setting, f);
            if(root->rp != NULL) Display(root->rp, setting, f);
            if(root->sc != NULL) fprintf(f, "%d\n", root->sc->i);
        break;

        default : printf("Invalid setting.\n");
        break;
    }
}

