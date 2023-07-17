
#include <stdio.h>
#include <ctype.h>

int main(int argc, char * argv[]){
    if(argc != 2){
        printf("Invalid.\n");
        return 1;
    }

    FILE * f = fopen(argv[1], "r");
    int cc = 0, wc = 0, lc = 1;
    int c = 0;
    char dummy[32];
    while(fscanf(f, "%s", dummy) != -1)
        wc++;

    fseek(f, 0, SEEK_SET);
    while((c = getc(f)) != EOF){
        if(c == '\n') lc++;
    
        if(isalnum(c)) cc++;
    }

    printf("%d %d %d\n", cc, wc, lc);
    return 0;
}