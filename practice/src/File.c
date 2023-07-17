
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main(){

    printf("breakpoitnerxfggn");
    FILE *first = NULL;
    first = fopen("my_c_file.txt1", "w+");
    if(first==NULL){
        perror("Error.");
        return -1;
    }

    fprintf(first, "12345678910111213141");

    /*fclose(first);
    first = fopen("my_c_file.txt", "r");

    if(fseek(first, 0, SEEK_SET)!=0{
        return -1;
    }*/
    
    char st[20];
    int c, i = 0;
    while(c!=EOF){
        st[i] = (char)fgetc(first);
        i++;
    }

    printf("Print contents : %s", st);
    fclose(first);
    return 0;
}