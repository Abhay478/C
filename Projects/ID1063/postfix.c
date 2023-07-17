
#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int val;
    struct n * lp;
    struct n * rp;
} node;


//strlen() from string.h
int len(char * s)
{
    int i;
    for(i = 0; s[i] != 0; i++);
    return i;
}

//reverses string
void reverse(char * s) 
{
    int temp;
    int l = len(s);
    for(int i = 0; i < l/2; i++){
        temp = s[i];
        s[i] = s[l - i - 1];
        s[l - i - 1] = temp;
    }
}

//isnum() from ctype.h
int dig(char a)
{
    if(a < '0' || a > '9') return 0;
    else return 1;
}

//postfix insertion into a binary tree
node * totree(char ** s)
{
    int l = len(*s);
    node * root = (node *)malloc(sizeof(node));
    root->val = (*s)[0];
    if(dig((*s)[0])){
        root->lp = NULL;
        root->rp = NULL;
        return root;
    }
    (*s)++;
    root->rp = totree(s);
    (*s)++;
    root->lp = totree(s);

    return root;
}

//inorder traversal of tree
int eval(node * root)
{
    if(dig(root->val)) return root->val - '0';
    switch(root->val){
        case '+' : return eval(root->lp) + eval(root->rp);
        
        case '-' : return eval(root->lp) - eval(root->rp);
        
        case '*' : return eval(root->lp) * eval(root->rp);
        
        default : return -1;
    }
}

//free tree
void wipe(node * root)
{
    if(root == NULL) return;
    wipe(root->lp);
    wipe(root->rp);
    free(root);
    return;
}

int main()
{
    char * str;
    size_t n;
    getline(&str, &n, stdin);
    int l = len(str);
    str[l - 1] = 0;

    reverse(str);
    
    node * root = totree(&str);
    
    printf("%d\n", eval(root));

    wipe(root);
    return 0;
}