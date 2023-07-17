


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <setjmp.h>
#include <assert.h>
#include <AssertMacros.h>
#include <bitstring.h>
#include <complex.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <search.h>
#include <signal.h>
#include <stdarg.h>
#include <struct.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#ifdef LIM
#undef LIM
#endif
#ifdef TLIM
#undef TLIM
#endif
#ifdef K
#undef K
#endif
#ifdef T
#undef T
#endif
#ifdef L
#undef L
#endif
#ifdef J
#undef J
#endif

//Symbolic constants
#define LIM 256
#define TLIM 4096
#define K unsigned int //in bit fields only.
#define L long double
#define T unsigned long long int 
#define J double complex

#undef Scanner
#undef Complex_number
#undef sl_node
#undef dl_node
#undef tree_node

//unions and structs

union Scanner{
    int i;
    int x; //hexadecimal
    int o; //octal
    long int li;
    unsigned int u;
    J z;
    K k;
    T t;
    L ld;
    
    double d;

    char c;
    char * s;
};

struct Complex_Number {
    double real, imag;
};

//singly linked
typedef struct sl_node{
    union Scanner sc;
    struct sl_node * next;
} node;
//doubly linked
typedef struct dl_node{
    union Scanner sc;
    struct dl_node * next;
    struct dl_node * prev;
} Node;
typedef struct tree_node{
    union Scanner * sc;
    struct tree_node * parent;
    struct tree_node * rp;
    struct tree_node * lp;
} NODE;

//hyperG.c
//Pocchammer symbol.
L Poch(L q, int n);

//more macros
#define Fact(n) (T)Poch(1.0, n)
#define lFact(n) (L)Poch(1.0, n)
#define P(n, r) Fact(n)/Fact(n - r)
#define C(n, r) P(n, r)/Fact(r)
#define rC(n, r) C(n + r - 1, r)
#define Alt(n) pow(-1, n)
#define Tetr(n) pow(n, n)
#define expG(a, n) pow(a, n)/lFact(n)


//alloc.c
//allocates required memory to string
void salloc(char ** in, FILE * req_f, int delim, bool ignoreBlanks);

//allocates required memory to int array
int ialloc(int ** in, FILE * req_f, int term);
int Init_pointer(int ** a, ...);


//GET.c
void * Get(char * var_nm, char * data_type);

//Accept.c
J Join(struct Complex_Number cnum);


struct Complex_Number Split(J cnum);


J Accept();

//pol_diff.c
L * Diff(int degree, L * coef);


L * Teg(int degree, L * coef, L teg_cons);


//palin.c, check_reps.c
void InSort(char ** A);
void InTSort(int ** A);
int * check_rep_s(char * a);
int * check_rep_i(int * a, int l);
int sgn(void * v1, void * v2);
bool isAnag(char * s1, char * s2);
void perm(int * dig, int l);

//macros

//hyperG.c
L hyp(L z, int n_up, int n_down, ...);


T rP(int n, int r, int * d);

//mobs.c
bool Prime(int n);
bool sprp(int n, int b);
#define fast_prime(n) ((n) == 3 || (sprp(n, 2) && sprp(n, 7) && sprp(n, 61))) ? (true) : (false)

int getprime(int n);
int mobs(T x);
L inv_zeta(T x);
L eval(L * Coef, L val, int degree);
L Lamb_W(L a);
L Lamb_ser(int (*f)(T ), L q);
T * Divi(T x);

#define BEGINNING 0
#define END -1
#define DEFAULT 1
#define ALL_CASES 2
#define ALL -2

node * merge(node * left, node * right);
node * sort(node * head);
void s_insert(node ** head, int setting, node * new);
node * sform(int n);

Node * Merge(Node * left, Node * right);
Node * Sort(Node * head);
Node * dform(int n);


#define IN_ORDER 0
#define PRE_ORDER 1
#define POST_ORDER -1
void t_insert(NODE * const root, NODE * new);
bool is_leaf(NODE * current);
NODE * tform(int n);
NODE * search(NODE * root, int n);
void wipe(NODE * root);
void Display(NODE * root, int setting, FILE * f);

int comp(const void * a, const void * b);
bool Search(int * a, int x);

void print(int * a, char sep, bool order);