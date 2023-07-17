
#include "my_header.h"


bool prime(T x)
{
    for(T i = 2; i <= sqrt(x); i++){
        if(!(x%i))
            return false;
    }
    return true;
}

bool sprp(int n, int b)
{
    int d = n - 1;
    int s = 0;
    while(d%2 == 0){
        d /= 2;
        s++;
    }
    if(pow(b, d)%n == 1) return true;
    for(int r = 0; r < s; r++)
        if(pow(b, d*pow(2, r))%n == n - 1) return true;
    return false;
}

bool fast_prime(int n){
    if(sprp(n, 2) && sprp(n, 7) && sprp(n, 61)) return true;
    else return false;
}

void factor_print(T y){
    T k, i = 2;
    printf("Factors of the given number are : \n");
    for(i = 2; i<=sqrt(y); i++){
        if(y%i==0){
            printf("%lld\n%lld\n", i, y/i);
            k++;
        }
    }

    
}

int main(){
    while(true){
        T a = *(T *)Get("number", "T");
        switch(a){
            case -1 : 
                printf("%lld", clock());
                return 0;
            
            case 1 : perror("Invalid input.");
                break;
            default : 
                switch(prime(a)){
                    case 1 : printf("Number is prime.\n"); 
                        break;
                    case 0 : printf("Number is not prime.\n");
                        
                        factor_print(a);
                        break;
                }
                break;

        }
    }    
    return 0;
}
