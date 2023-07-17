
#include <stdio.h>
#include <stdbool.h>

void prime(int x);
int main(){
    printf("Enter upper bound.");
    int u;
    scanf("%d", &u);
    
    for(int a = 2; a <= u; a++){
        prime(a);
    }    
    return 0;

}

void prime(int x){
    int n = 0;
    for(int i = 1; i<=x; i++){
        n += (x%i==0)? 1 : 0;
    }
    if(n==2){
        printf("%d\n", x);
    }
}    