
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main(){

    char st[] = "a string";
    char *p = st;
    
    while(p< st + strlen(st)){
        //*p += 1;
        printf("%c, %p\n", *p, p++);
        
    }
    return 0;
}


