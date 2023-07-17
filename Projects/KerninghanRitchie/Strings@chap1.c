
#include <my_header.h>

void Detab(char * s);
void Entab(char * s);
//void Fold(char * s);
void Multiplexer(char * st);
int main()
{
    printf("Enter string.");
    char * str = NULL;
    alloc(&str, stdin, '$');
    Multiplexer(str);
    return 0;
}


void Detab(char * s)
{
    int len = strlen(s);
    int k = 0;
    char * o = (char *)calloc(len, sizeof(char));
    for(int i = 0; i < len; i++){
        if(s[i]=='\t'){
            k++;
            o = realloc(o,strlen(o) + 3);
            o[i + 3*k - 3] = ' ';
            o[i + 3*k - 2] = ' ';
            o[i + 3*k - 1] = ' ';
            o[i + 3*k] = ' ';
            i++;
        }
        o[i + 3*k] = s[i];
    }
    printf("%s", o);
}

void Entab(char * s){
    int len = strlen(s);
    int k = 0;
    
    
    char * o = (char *)calloc(len, sizeof(char));
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i]==' '&&s[i+1]==' '&&s[i+2]==' '&&s[i+3]==' '){
            o[i] = '\t';
            k++;
            i += 4;
        }
        o[i - 3*k] = s[i];   
    }
    printf("%s", o);
}


void Multiplexer(char * st)
{
    int k;
    printf("Enter \n1 - detab\n2 - entab\n");
    int m = scanf("%d", &k);
    switch(k){
        case 1 : Detab(st);
        break;
        case 2 : Entab(st);
        break;
        
        default : perror("Wrong usage.");
        break;
    }
    
}