
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if(--argc == 0){
        printf("Invalid no. args.");
        return 1;
    }
    int set;
    for(int i = 0; i < argc; i++){
        for(int j = 0; j < strlen(argv[i + 1]); j++)
            if((argv[i + 1][j] - 'A' + 1) < 10*((i + 1)%3 == 0 ? 3 : (i + 1)%3)) set++;
        
        printf("%d ", set);
        set = 0;
    }
    return 0;

}