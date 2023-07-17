
#include <stdio.h>
void Parity(int n);
void Sum(int sum);
void Product(int prod);
void Asterisks(int n);
void Fib(int n);

int main()
{
    printf("Functions : \n Parity : 1 \n Sum : 2 \n Product : 3 \n Asterisks : 4 \n Fib : 5 \n");
    int ch;
    scanf("%d", &ch);
    printf("Enter number.");
    int n;
    scanf("%d", &n);
    switch(ch){
        case 1 : Parity(n); 
            break;
        case 2 : Sum(n);
            break;
        case 3 : Product(n);
            break;
        case 4 : Asterisks(n);
            break;
        case 5 : Fib(n);
            break;
        default : printf("Invalid.");
            break;
    }

    return 0;
}

//Part 1
void Parity(int n)
{
    printf("%s", n%2 ? "Odd." : "Even.");
}

void Sum(int sum)
{
    for(int i = 1; i <  sum; i++){
        printf("%d + %d = %d\n", i, sum - i, sum);
    }
}

void Product(int prod)
{
    for(int i = 1; i <= prod; i++){
        if(!(prod%i))
            printf("%d x %d = %d\n", i, prod / i, prod);
    }
}


//part 2
void Asterisks(int n)
{
    int k = 0;
    while(n>0){
        printf(" * ");
        k++;
        if(k==n){
            printf("\n");
            k = 0;
            n--;
        }
    }
}

void Fib(int n)
{
    int t_p;
    printf("Enter seed 1.");
    scanf("%d", &t_p);

    int t;
    printf("Enter seed 2.");
    scanf("%d", &t);

    int t_n;
    printf("%d \n %d \n", t_p, t);
    
    for(int i = 1; i <= n; i++){
        t_n = t + t_p;
        printf("%d \n", t_n);
        t_p = t;
        t = t_n;
    }

}