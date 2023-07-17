
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


int main(){

    FILE *p_this = NULL;
    p_this = fopen("my_c_file1", "w+");

    if(p_this == NULL){
        perror("Error.");
        exit(-1);
    }
    fputs("etxrcjtyb", p_this);

    fclose(p_this);

    p_this = fopen("my_c_file1", "r");
    char str[20] = {0};

    if(fgets(str, 20, p_this)!=NULL){
        puts(str);
    }

    printf("stuff : %s\n", str);

    if(fseek(p_this, 0, SEEK_SET)!=0){
        exit(-1);
    }
    
    
    int c;
    while(c!=EOF){
        c = fgetc(p_this);
        printf("%c\n", c);
    }
    fclose(p_this);
    printf("Breakpoint");
}