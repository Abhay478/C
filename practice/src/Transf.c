
#include "my_header.h"

NODE * array_to_tree(int * a)
{
    NODE * root = tform(a[1]);

    for(int i = 1; i <= a[0]; i++)
        insert(root, tform(a[i]));
    

    return root;
}

int * tree_to_array(NODE * root)
{
    FILE * f = fopen("Dummy.txt", "r+");
    Display(root, IN_ORDER, f);

    int * out = malloc(2*sizeof(int));
    out[0] = 0;
    fseek(f, 0, SEEK_SET);
    for(int i = 1; fscanf(f, "%d", &out[i]) != -1; i++){
        out[0] = i;
        out = realloc(out, (out[0] + 2)*sizeof(int));
    }
    
    fclose(f);
    return out;
}

/*node * array_to_slist(int * a)
{
    node * head = sform(a[1]);
    for(int i = 1; i <= a[0]; i++){
        s_insert(&head, DEFAULT, sform(a[i]));
    }
       
    return head;
}*/

int * slist_to_array(node * head)
{
    int * a = malloc(sizeof(int));
    a[0] = 0;
    for(int i = 1; head != NULL; i++){
        a = realloc(a, (i + 1)*sizeof(int));
        a[i] = head->sc.i;
        head = head->next;
    }

    return a;
}


