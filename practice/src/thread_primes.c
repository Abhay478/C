
#include "my_header.h"

#define maketh pthread_create
#define jth pthread_join
#define exth pthread_exit
#define th pthread_t

typedef struct dat{
    int n;
    struct dat * next;
} dat;

void * p_rand(void * v){
    FILE * f = (FILE *)v;
    for(int i = 0; i < 50000; i++)
        fprintf(f, "%ld\n", random());
    
    return NULL;
}

void populate(FILE * f1, FILE * f2){
    th t1, t2;
    maketh(&t1, NULL, p_rand, f1);
    maketh(&t2, NULL, p_rand, f2);
    jth(t1, NULL);
    jth(t2, NULL);
    return;
    
}

bool sprp(int n, int b)
{
    int d = n - 1;
    int s = 0;
    while(d%2 == 0){
        d /= 2;
        s++;
    }
    if((int)pow(b, d)%n == 1) return true;
    for(int r = 0; r < s; r++)
        if((int)pow(b, (int)d*pow(2, r))%n == n - 1) return true;
    return false;
}

bool prime(T x)
{
    for(T i = 2; i <= sqrt(x); i++){
        if(!(x%i))
            return false;
    }
    return true;
}


void * count_in_thread(void * v){
    dat * current = (dat *)v;
    int count = 0;
    while(current != NULL){
        count += prime(current->n)?1 : 0;
        current = current->next;
    }

    printf("%d\n", count);
    exth((void *) count);
}

void count_primes(FILE * f1, FILE * f2){
    dat * head1 = malloc(sizeof(dat));
    dat * c1 = head1;
    dat * head2 = malloc(sizeof(dat));
    dat * c2 = head2;

    int t;
    bool b = true;
    while(fscanf(f, "%d", &t) != -1){
        if(b){
            c1->n = t;
            c1->next = malloc(sizeof(dat));
            c1 = c1->next;
        }
        else{
            c2->n = t;
            c2->next = malloc(sizeof(dat));
            c2 = c2->next;
        }
        b = !b;
    }

    int count = 0;
    th t1, t2;
    void * count1 = 0;
    void * count2 = 0;
    maketh(&t1, NULL, count_in_thread, head1);
    maketh(&t2, NULL, count_in_thread, head2);

    jth(t1, &count1);
    jth(t2, &count2);
    count += (int)count1;
    count += (int)count2;

    printf("%d\n", count);
}


int main(){
    FILE * f1 = fopen("random.dat", "r+");
    FILE * f2 = fopen("random1.dat", "r+");
    populate(f1, f2);
    count_primes(f1, f2);
}
