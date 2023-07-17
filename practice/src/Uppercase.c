 
 #include <stdio.h>
 #include <string.h>

int main(){
    printf("Enter string.\n");
    char st[140];
    scanf("%s", st);
    for(int i = 0; st[i]!='\0'; ++i){
        if((int)st[i]>96){
            st[i] = st[i] - 32;
        }
    }
    printf("\n%s", st);
    return 0;
}




