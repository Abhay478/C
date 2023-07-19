#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* Testing C function.
int main() {
    printf("Hello, world.\n");
}
*/

#define NODE_SIZE 4
typedef enum InsertStatus {Duplicate, Normal} InsertStatus;
typedef enum PromoteStatus {NewRoot, Normal} PromoteStatus;
typedef enum BorrowStatus {Sibling, Parent} BorrowStatus;

typedef struct node {
    int kbuf[NODE_SIZE];
    node * cbuf[NODE_SIZE + 1];
    node * pr;
    int sz; // the index to put things at.
    bool lf;
} node;

typedef struct btree {
    node * root;
    // Well, what else am I going to put here?
} btree;

typedef struct SplitTuple {
    node * left;
    node * right;
    int k
} SplitTuple;

node * init_node() {
    node * out = calloc(1, sizeof(node));
    out->lf = true;
    return out;
}

/*
bool is_full(node * self) {
    return self->sz == -1; // So you gotta set to -1 once the node is full.
}

void flush_node(node * self) {
    for(int i = 0; i < NODE_SIZE; i++) {
        self->cbuf[i] = 0;
        self->kbuf[i] = 0;
    }

    self->sz = 0;
}

int push_to_leaf(node * self, int val) {
    if(!self->lf) return 1; // not a leaf, so you really shouldn't be calling this.
    if(self->sz == NODE_SIZE) return -1; // full

    // find the correct position to insert
    int i;
    for(i = 0; i < self->sz; i++) 
        if(self->kbuf[i] > val) break;
    
    // insert
    if(i == self->sz) self->kbuf[self->sz] = val;
    else {
        for(int j = i + 1; j <= self->sz; j++) {
            self->kbuf[j] = self->kbuf[j - 1];
        }
        self->kbuf[i] = val;
    }

    // update sz
    self->sz++;
    return 0;
}
*/

SplitTuple * split_init(node * left, node * right, int k) {
    SplitTuple * next = calloc(1, sizeof(SplitTuple));
    next->k = k;
    next->left = left;
    next->right = right;

    return next;
}

SplitTuple * split(int * kbuf, int * cbuf, node * self) {
    node * left = init_node();
    node * right = init_node();

    memcpy(left->kbuf, kbuf, NODE_SIZE/2); // keys
    memcpy(left->cbuf, self->cbuf, NODE_SIZE/2 + 1); // children
    // parent
    for(int i = 0; i <= NODE_SIZE/2; i++) {
        left->cbuf[i]->pr = left;
    }

    memcpy(right->kbuf, kbuf + NODE_SIZE/2 + 1, NODE_SIZE/2); // keys
    memcpy(right->cbuf, self->cbuf + NODE_SIZE/2 + 1, NODE_SIZE/2);// children
    // parent
    for(int i = 0; i < NODE_SIZE/2; i++) {
        right->cbuf[i]->pr = right;
    }

    left->sz = right->sz = NODE_SIZE/2;
    left->lf = right->lf = self->lf;
    left->pr = right->pr = self->pr;

    SplitTuple * next = split_init(left, right, kbuf[NODE_SIZE/2]);
    return next;
}

InsertStatus push_key(int * kbuf, int k, int sz) {
    int i;
    for(i = 0; i < sz - 1; i++) {
        if(kbuf[i] == k) return Duplicate;
        if(kbuf[i] > k) break;
    }
    for(int j = i + 1; j < sz; j++) {
        kbuf[j] = kbuf[j - 1];
    }
    kbuf[i] = k;
    return Normal;
}

PromoteStatus promote(node * self, SplitTuple * tup, node ** root) {
    if(self->sz == NODE_SIZE) {
        // new buffers.
        int kbuf[NODE_SIZE + 1];
        node * cbuf[NODE_SIZE + 2];

        // init buffers
        memcpy(kbuf, self->kbuf, NODE_SIZE);
        memcpy(cbuf, self->cbuf, NODE_SIZE + 1);

        // add key and children to buffers
        push_key(kbuf, tup->k, NODE_SIZE + 1);
        if(tup->left || tup->right) { // if both null, skip. Saves time.
            int i;
            for(i = 0; i <= NODE_SIZE; i++) if(kbuf[i] == tup->k) break;
            for(int j = i + 1; j <= NODE_SIZE; j++) cbuf[j] = cbuf[j - 1];
            cbuf[i] = tup->left;
            cbuf[i + 1] = tup->right;
        }

        // Split buffers
        SplitTuple * next = split(kbuf, cbuf, self);
        // new root
        if(!self->pr) {
            node * rt = init_node(); 
            rt->lf = false;
            rt->kbuf[0] = next->k;
            rt->cbuf[0] = next->left;
            next->left->pr = rt;
            rt->cbuf[1] = next->right;
            next->right->pr = rt;
            rt->sz++;
            *root = rt;
            free(self);
            return NewRoot; // New root status
        }
        // recursion
        PromoteStatus out = promote(self->pr, next, root);
        free(self);
        free(tup);
        return out;

    }
    else {
        push_key(self->kbuf, tup->k, self->sz);
        if(tup->left || tup->right) { // if both null, skip. Saves time.
            int i;
            for(i = 0; i <= NODE_SIZE; i++) {
                if(self->kbuf[i] == tup->k) break;
            }
            for(int j = i + 1; j <= NODE_SIZE; j++) {
                self->cbuf[j] = self->cbuf[j - 1];
            }
            self->cbuf[i] = tup->left;
            self->cbuf[i + 1] = tup->right;
            tup->left->pr = tup->right->pr = self;
        }
        self->sz++;

        return Normal;
    }

}

BorrowStatus borrow(node * self) {
    // check siblings.
    int index;
    node * p = self->pr;
    for(index = 0; index < self->pr->sz; index++) {
        if(p->cbuf[index] == self) break;
    }

    // left
    if(p->cbuf[index - 1]->sz > NODE_SIZE/2) {
        node * sib = p->cbuf[index - 1];
        int k = sib->kbuf[--sib->sz];
        sib->kbuf[sib->sz] = 0;

        for(int i = 1; i <= self->sz; i++) {
            self->kbuf[i] = self->kbuf[i - 1];
        }
        self->sz++;
        self->kbuf[0] = k;
        return Sibling;
    }

    // right
    if(p->cbuf[index + 1]->sz > NODE_SIZE/2) {
        node * sib = p->cbuf[index + 1];
        int k = sib->kbuf[0];
        for(int i = 0; i < self->sz - 1; i++) {
            sib->kbuf[i] = sib->kbuf[i + 1];
        }
        sib->kbuf[--sib->sz] = 0;

        self->kbuf[self->sz++] = k;
        return Sibling;
    }

    // Parent
    int k = p->kbuf[index - 1];
    node * sib = p->cbuf[index - 1];
    for(int i = index; i < p->sz; i++) {
        p->cbuf[i] = p->cbuf[i + 1];
        p->kbuf[i - 1] = p->kbuf[i];
    }
    sib->kbuf[sib->sz++] = k;
    for(int i = 0; i < self->sz; i++) {
        sib->kbuf[sib->sz++] = self->kbuf[i];
        sib->cbuf[sib->sz] = self->cbuf[i];
    }
    // sib->cbuf[sib->sz]

}

btree * init_tree() {
    btree * out = calloc(1, sizeof(btree));
    out->root = init_node();
    return out;
}

InsertStatus insert(btree * self, int k) {
    node * current = self->root;
    while(!current->lf) {
        for(int i = 0; i < current->sz; i++) {
            if(k == current->kbuf[i]) return Duplicate;
            if(k < current->kbuf[i]) {
                current = current->cbuf[i];
                goto l1;
            }
        }
        current = current->cbuf[current->sz]; 

        l1: // if currect child found, jump here.
    }

    if(current->sz < NODE_SIZE) push_key(current->kbuf, k, current->sz);
    else {
        SplitTuple * s = calloc(1, sizeof(SplitTuple));
        s->k = k;
        promote(current, &s, &self->root);
    }
}

bool search_tree(btree * self, int k) {
    node * current = self->root;
    while(!current->lf) {
        for(int i = 0; i < current->sz; i++) {
            if(current->kbuf[i] == k) return true;
            if(current->kbuf[i] > k) {
                current = current->cbuf[i]; 
                goto l2;
            }
        }
        current = current->cbuf[current->sz];
        l2:
    }
    for(int i = 0; i < current->sz; i++) if(current->kbuf[i] == k) return true;
    
    return false;
}

