
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct var_nm{
    char * s;
    struct var_nm * next;
};

void Display(struct var_nm ** head_array, int l);

int req_key(char * s)
{
    if(!strcmp(s, "struct")) return 2;

    else if(!strcmp(s, "int") || !strcmp(s, "char") || !strcmp(s, "float") || !strcmp(s, "double") || !strcmp(s, "bool")
        || !strcmp(s, "void")) return 1;

    else return 0;
}

char * get_var(FILE * f)
{
    static long off = 0;
    char * dummy = (char *)calloc(31, sizeof(char));
    char * out = (char *)calloc(31, sizeof(char));
    int x;
    fseek(f, off, SEEK_SET);
    x = getc(f);
    int c;
    switch(x){
        case EOF :
            out = "EOF";
            return out;
        break;
        case '\"' :
            while((x = getc(f)) != '\"')
                ;
        break;
        case '/' :
            c = getc(f);
            if(c == '*')
                while((x = getc(f)) != '*')
                    if((x = getc(f)) == '/') 
                        break;
        break;
        default : ungetc(x, f);
        break;
    }
    

    while(fscanf(f, "%s", dummy) != -1){
        if(req_key(dummy) == 1){
            while((x = getc(f)) == '*' || isblank(x))
                ;
            ungetc(x, f);
            fscanf(f, "%s", out);
            if((x = getc(f)) == '(')
                out = "";
            
            break;
        }
        if(req_key(dummy) == 2){// for structs
            fscanf(f, "%s", dummy); // struct name
            while((x = getc(f)) == '*' || isblank(x))
                ;
            fscanf(f, "%s", out);
            if((x = getc(f)) == '(')
                out = "";
            
            break;
        }
    }
    off = ftell(f);
    return out;
}

void printlist(struct var_nm * head)
{
    struct var_nm * current = head;
    while(current != NULL){
        printf("%s\n", current->s);
        current = current->next;
    }
    printf("\n\n\n\n\n\n");
}

void Display(struct var_nm ** head_array, int l)
{
    /*struct var_nm * tmp = malloc(sizeof(struct var_nm));
    for(int i = 0; i < l; i++)
        for(int j = i; j < l; j++)
            if(strcmp((head_array[i])->s, (head_array[j])->s) > 0){
                tmp = head_array[i];
                head_array[i] = head_array[j];
                head_array[j] = tmp;
            }*/
        
    
    for(int i = 0; i < l; i++)
        printlist(head_array[i]);
    
}

void var_groups(FILE * f, int cmp, struct var_nm ** head_array)
{
    int l = 1;
    struct var_nm * current;
    char * s1 = NULL;
        
    int i = 0;
    while(1){
        s1 = get_var(f);
        if(!strcmp(s1, "EOF")) break;

        for(i = 0; i < l; i++){
            current = head_array[i];
            while(current->next != NULL) current = current->next;

            if(!strncmp(s1, (current)->s, cmp)){
                struct var_nm * new = calloc(1, sizeof(struct var_nm));
                new->s = s1;
                current->next = new;
                new->next = NULL;
                break;
            }
        }

        if(i == l) {
            head_array = (struct var_nm **)realloc(head_array, sizeof(struct var_nm *)*(l + 1));
            head_array[l] = (struct var_nm *)calloc(1, sizeof(struct var_nm));
            (head_array[l])->s = s1;
            (head_array[l])->next = NULL;
            l++;
        }
            
    }

    Display(head_array, l);
}

void setbrac(FILE * f)
{
    int c;
    while ((c = getc(f)) != EOF){
        if(c == '(' || c == '{' || c == '['){
            ungetc((char)c,  f);
            putc(' ', f);
            
            fseek(f, 2, SEEK_CUR);
        }
        if( c == ')' || c == '}' || c == ']' || c == ';'){
            putc(' ', f);
            ungetc((char)c,  f);
            
            fseek(f, 2, SEEK_CUR);
        }
    }
    
}

int main()//int argc, char * argv[])
{
    /*if(argc != 2) {
        printf("Wrong usage.\n");
        return 0;
    }*/

    FILE * f = fopen("CHAP6.txt", "r+");
    setbrac(f); //adds one space before and after every bracket

    struct var_nm ** head_array = (struct var_nm **)calloc(1, sizeof(struct var_nm *));
    head_array[0] = (struct var_nm *)calloc(1, sizeof(struct var_nm));
    head_array[0]->s = "";
    head_array[0]->next = NULL;

    var_groups(f, 6/*atoi(argv[1])*/, head_array);
    fclose(f);
    return 0;
}