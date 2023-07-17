#include "my_header.h"

#define maketh pthread_create
#define jth pthread_join
#define exth pthread_exit
#define th pthread_t

void * upper_poch(void * a)
{
    // L q = *(*((L **)a));
    // L n = *(*((L **)a) + 1);

    L q = ((L *)a)[0];
    L n = ((L *)a)[1];

    // printf("Upper : %lf %lf\n", q, n);

    L * out = malloc(sizeof(L));
    *out = 1;
    for(int i = 0; i < n; i++){
        *out *= q + i + 1;
    }

    exth((void *)out);

}

void * lower_poch(void * a)
{
    // L q = *(*((L **)a));
    // L n = *(*((L **)a) + 1);

    L q = ((L *)a)[0];
    L n = ((L *)a)[1];
    // printf("Lower : %lf %lf\n", q, n);

    L * out = malloc(sizeof(L));
    *out = 1;
    for(int i = 0; i < n; i++){
        *out *= q - i;
    }

    exth((void *)out);

}

L * catalan(L n)
{
    th t1, t2;
    L out[] = {n, n};
    maketh(&t1, NULL, upper_poch, out);
    maketh(&t2, NULL, lower_poch, out);

    L * res1, * res2;
    jth(t1, (void **)&res1);
    // printf("%lf\n", *res1);

    jth(t2, (void **)&res2);
    L * res = malloc(sizeof(L));

    *res = (*res1)/((*res2) * (n + 1));

    return res;
    
}
int main()
{

    // FILE * f = fopen("cat.dat", "w");

    // for(int i = 1; i <= 15; i++)
    // {
    //     fprintf(f, "%lf\n", (*catalan(i))/(1 << 2*i));
    // }

    L n = 0;
    printf("Enter number.\n");
    while(scanf("%Lf", &n) != -1 && n != -1){
        printf("%lld\n", (long long int)*catalan(n));
    }

    // for(int i = 0; i < 10;i++){
    //     int * a = (int *)malloc(sizeof(int));
    //     char * s = (char *)malloc(sizeof(char));
    //     printf("%p %p\n", a, s);
    //     // printf("%d %d %d %d\n", *a++, *a++, *a++, *a++);
    //     // printf("%p\n", a);
    // }
    
    
}