#include <stdio.h>
#include <stdlib.h>

typedef struct t{
    int n;
    struct t * left;
    struct t * right;
} node;
node * make_tree(int * a, int m, int n, node * root);

void morris(node * root, FILE * f)
{
    node * current, * prev;
    if(root == NULL) return;

    current = root;
    while(current != NULL){
        //base case
        if(current->left == NULL){
            fprintf(f, "%d\n", current->n);
            current = current->right;
        }
        else{
            //preceeding element
            prev = current->left;
            while(prev->right != NULL && prev->right != current) prev = prev->right;

            //creates stack route  
            if(prev->right == NULL){
                prev->right = current;
                current = current->left;
            }
            //if stack route
            else{
                prev->right = NULL; //removes stack route
                fprintf(f, "%d\n", current->n); //prints parent
                current = current->right; //right subtree
            }
        }
    }

}

node * make_t(int n)
{
    node * new = (node *)malloc(sizeof(node));
    new->n = n;
    new->left = NULL;
    new->right = NULL;
 
    return new;
}

int random_in(int m, int n)
{
    int a = random();
    if(n < m) return m;
    int diff = n - m + 1;
    a %= diff;
    a += m;

    return a;
}

// int ** partition(int * a, int k)
// {
//     item * less = calloc(1, sizeof(item));
//     item * more = calloc(1, sizeof(item));
//     item * cl = less;
//     item * cm = more;
//     int count_l = 0;
//     int count_m = 0;
//     for(int i = 1; i <= a[0]; i++){
//         if(a[i] < a[k]){
//             count_l++;
//             cl->n = a[i];
//             if(i < a[0]) {cl->next = calloc(1, sizeof(item));
//             cl = cl->next;} 
//         }
//         if(a[i] > a[k]){
//             count_m++;
//             cm->n = a[i];
//             if(i < a[0]) {cm->next = calloc(1, sizeof(item));
//             cm = cm->next;}
//         }
//     }
//     int ** out = calloc(2, sizeof(int *));
//     out[0] = calloc(count_l + 1, sizeof(int));
//     out[0][0] = count_l;
//     out[1] = calloc(count_m + 1, sizeof(int));
//     out[1][0] = count_m;
// }
// item * make_l(int n)
// {
//     item * out = calloc(1, sizeof(item));
//     out->n = n;
//     out->next = NULL;
//     return out;
// }
// item * a2l(int * a)
// {
//     item * head = make_l(a[1]);
//     item * current = head;
//     item * new;
//     for(int i = 2; i <= a[0]; i++){
//         new = make_l(a[i]);
//         current->next = new;
//         current = new;
//         new = NULL;
//     }
//
//     return head;
// }

int * sort(int * a){
    
    int l = a[0]; //number of relevant elements

    //maximal element
    int k = -1; 
    for(int i = 1; i <= a[0]; i++){
        if(a[i] > k) k = a[i];
    }

    //minimal element
    int m = k;
    for(int i = 1; i <= a[0]; i++){
        if(a[i] < m) m = a[i];
    }
    m--;

    //fitting everything into [1, something]
    for(int i = 1; i <= a[0]; i++){
        a[i] -= m;
    }

    k -= m;

    //creates the hash-array
    int * temp = calloc(k + 1, sizeof(int));
    //populates it with the number of elements
    for(int i = 1; i <= k; i++){
        temp[a[i]]++;
    }

    // for(int i = 1; i <= k; i++ ){
    //     printf("%d\n", temp[i]);
    // }

    //maps temp back onto a
    int ind = 1;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= temp[i]; j++){
            a[ind] = i;
            ind++;
        }
    }
    free(temp);
    // for(int i = 1; i <= 10; i++ ){
    //     printf("%d\n", a[i]);
    // }

    //restores the values of the original array
    for(int i = 1; i <= a[0]; i++){
        a[i] += m;
    }
    return a;
}

node * from_array(int * a, node * root)
{
    a = sort(a);
    // for(int i = 1; i <= a[0]; i++)
    //     printf("%d\n", a[i]);
    make_tree(a, 1, a[0], root);

    return root;
}

node * make_tree(int * a, int m, int n, node * root)
{
    if(m > n) return NULL;
    //fix the odd-even mess
    // int t = random_in(m, n);
    int t = (m + n)/2;
    if(root == NULL) root = make_t(a[t]);
    if(n - m == 0){
        return root;
    }
    make_tree(a, m, t - 1, root->left);
    make_tree(a, t + 1, n, root->right);
    return root;

}

int main()
{
    int a[] = {7, 6, 5, 4, 3, 2, 1, 0};
    node * root = NULL;
    from_array(a, root);
 
    morris(root, stdin);
 
    return 0;
}
