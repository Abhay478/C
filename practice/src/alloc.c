
#include "my_header.h"

void salloc(char ** in, FILE * req_f, int term, bool ignoreBlanks)
{
    *in = calloc(1, sizeof(char));
    int c = 0;
    int count = 1;
        
    while((c = getc(req_f)) != EOF && c != term && count < LIM - 1){
        if(ignoreBlanks && isblank(c)) continue;
        *in = realloc(*in, count + 1);
        (*in)[count - 1] = c;
        count++;
    }
        
    (*in)[count - 1] = '\0';
}


int ialloc(int ** in, FILE * req_f, int term)
{
    *in = calloc(1, sizeof(int));
    int c = 0;
    int count = 1;
    

    while(fscanf(req_f, "%d", &c) != -1 && c != term && count < LIM - 1){
        if(c == term) return count - 1;
        *in = (int *)realloc(*in, count + 1);
        (*in)[count - 1] = c;
        count++;
    }

    return count - 1;
}    

/*int falloc(double ** in, FILE * req_f, char term)
{
    *in = calloc(1, sizeof(double));
    double c = 0;
    int ch;
    int count = 1;

    for(scanf("%lf",  &c), (ch = getc(req_f)); ch != EOF && (char)ch != term && count < LIM - 1; scanf("%lf",  &c), count++){
        *in = realloc(*in, count + 1);
        (*in)[count - 1] = c;
    }
    return count;
}*/

int Init_pointer(int ** a, ...)
{
    va_list ap;
    va_start(ap, a);

    int l = va_arg(ap, int);

    *a = malloc(l*sizeof(int));
    (*a)[0] = l;
    int i;
    for(i = 1; i <= l; i++)
        (*a)[i] = va_arg(ap, int);

    if(i != l) return 1;
    return 0;
}


/*Please enter one of the following.
int
long
float
double
unsigned int
K - unsigned int, to be used in bit fields only
T - unsigned long long int
L - long double
char
char *
char * -d Ignores blanks
string
string -d ignores blanks (d for dense)
hexadecimal
octal*/ 
void * Get(char * var_nm, char * data_type)
{
    union Scanner sc;
    int i = 0;
    
    void * ret;

    printf("Enter %s.\n", var_nm);
    
    if((!strcmp(data_type, "string")) || (!strcmp(data_type, "char *"))){
        sc.s = NULL;
        salloc(&(sc.s),stdin, '\n', 0);
        ret = sc.s;
    }

    if((!strcmp(data_type, "string -d")) || (!strcmp(data_type, "char * -d"))){
        sc.s = NULL;
        salloc(&(sc.s),stdin, '\n', 1);
        ret = sc.s;
    }
    
    else if(!strcmp(data_type, "int")){
        sc.i = 0;
        
        scanf("%i", &(sc.i));
        ret = &(sc.i);
    }

    else if(!strcmp(data_type, "hexadecimal")){
        sc.x = 0;
        
        scanf("%x", &(sc.x));
        ret = &(sc.x);
    }

    else if(!strcmp(data_type, "octal")){
        sc.o = 0;
        
        scanf("%o", &(sc.o));
        ret = &(sc.o);
    }

    else if(!strcmp(data_type, "long")){
        sc.li = 0;
        
        scanf("%li", &(sc.li));
        ret = &(sc.li);
    }

    else if(!strcmp(data_type, "unsigned int") || !strcmp(data_type, "K")){
        sc.u = 0;
        
        scanf("%u", &(sc.u));
        ret = &(sc.u);
    }

    else if(!strcmp(data_type, "char")){
        sc.c = 0;
        
        scanf("%c", &(sc.c));
        ret = (void *)&(sc.c);
    }

    else if((!strcmp(data_type, "double")) || (!strcmp(data_type, "float"))){
        sc.d = 0;
        
        scanf("%lf", &(sc.d));
        ret = &(sc.d);
    }

    else if(!strcmp(data_type, "T")){
        sc.t = 0;
        
        scanf("%llu", &(sc.t));
        ret = (void *)&(sc.t);
    }

    else if(!strcmp(data_type, "L")){
        sc.t = 0;
        
        scanf("%Lf", &(sc.ld));
        ret = (void *)&(sc.ld);
    }

    else{
        printf("Given data type incompatible.");
    }

    return ret;
}

