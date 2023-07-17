
#include "my_header.h"


char ** Detab(char * s_in, int length);
char ** Entab(char * s_in, int length);
char ** Fold(char * s_in, int length);
char ** Multiplexer(char * st, int length);

int length;

char ** s_out;

char ** Detab(char * s_in, int length)
{
    int l = length;
    s_out = (char **)malloc(length*sizeof(char *));
    
    for(int i = 0; i < length; i++)
        s_out[i] = (char *)calloc(1, sizeof(char));
    
    for(int i = 0; i < l; i++){
        if(s_in[i] == '\t'){
            s_out[i] = (char *)realloc(s_out[i], 5);
            s_out[i] = "    ";
            length += 3;
        }
        else
            *s_out[i] = s_in[i];
    }
    return s_out;
}

char ** Entab(char * s_in, int length)
{
    int l = length;
    s_out = (char **)calloc(length, sizeof(char *));
    
    for(int i = 0; i < l; i++)
        s_out[i] = (char *)calloc(1, sizeof(char));
    
    
    for(int i = 0; i < l; i++){
        if(!strcmp(strcat(s_in + i, ""), "    ")){
            *s_out[i] = '\t';
            i += 4;
            length -= 3;
        }
        else
            *s_out[i] = s_in[i];
    }
    return s_out;
}

void Code_Mode(int max, char * s_in){
    printf("Code mode.\n");
        for(int i = 0, k = 1; i < length; i++){
            if(i == max*k){
                s_out = (char **)realloc(s_out, (length + k)*sizeof(char));
                k++;
                *s_out[i] = '\n';
            }
            *s_out[i + k - 1] = (s_in[i]);
        }
}

void Text_Mode(int max, char * s_in)
{
    printf("Text mode.\n");
    int blank_flag = 0;
    int count = 0;
    // iterate through the string till end of string
    for(int i = 0, k = 1; i < length; i++){
        if(s_in[i] == ' ')
            blank_flag = i;
    //if there is a blank get the index position of the blank and plant the blank flag          
        *s_out[i] = s_in[i];

        count++;
    //check if the string has reached the max column
        if(count==max){
            if(blank_flag == 0){
                printf("Enter a sensible column limit. barring that, please switch to code mode.");
                return;
            }
    //fold the string if max column has reached , fold to current or prev blank position
            s_out[blank_flag] = "\n";
            k++;
            count = 0;
    //reset iterator to the prev blank
            i = blank_flag;
        }
    }
}

char ** Fold(char * s_in, int length)
{
    s_out = (char **)malloc(length*sizeof(char *));
    
    for(int i = 0; i < length; i++)
        s_out[i] = (char *)calloc(1,sizeof(char));
    
    printf("Enter : \n Text mode : 1\n Code mode : 0.");
    int mode;
    scanf("%d", &mode);

    printf("Enter maximum number of columns.");
    int mc;
    scanf("%d", &mc);

    if(mode == 0)
        Code_Mode(mc, s_in);
    else if(mode == 1)
        Text_Mode(mc, s_in);
    else
        printf("Enter valid mode.");

    return s_out;

}

char ** Multiplexer(char * st, int length)
{
    int k;
    printf("Enter \n1 - detab\n2 - entab\n3 - fold\n");
    scanf("%d", &k);
    switch(k){
        case 1 : return Detab(st,length);
        
        case 2 : return Entab(st, length);
        
        case 3 : return Fold(st, length);
        
        default : perror("Wrong usage.");
        return NULL;
    }
    
}

int main(void)
{
    printf("Enter string.\n");
    char * str = (char *)calloc(1, sizeof(char));
    int c = getchar(), i;
    for(i = 0;; c = getchar(), i++){
        str[i] = c;
        if(c == '$')
            break;
        str = (char *)realloc(str, i + 2);
    }
    str[i + 1] = '\0';
    length = strlen(str);
    Multiplexer(str, length);
    if(s_out == NULL){
        printf("Error has occurred.");
        return -1;
    }

    char * result = (char *)calloc(length, sizeof(char));
    for(int j = 0; j < strlen(str); j++)
        strcat(result, s_out[j]);

    printf("%s", result);   



    free(s_out);
    free(str);
    
    return 0;
}

