
#include <stdio.h>

void Cubic();
void minmax();
void ParCount();
void sqLess();
void composite();
int FP();
void PinFib();
void Taxicab();


void Cubic()
{
    int arr[20];
    for(int i = 0; i<20; i++){
        arr[i] = 3*i*i*i + 2*i*i + i + 42;
    }

    for(int i = 0; i<20; i++){
        printf("%d\n", arr[i]);
    }
}

void minmax()
{
    int a, b;
    printf("Enter number.\n");
    scanf("%d", &a);

    printf("Enter one more number.\n");
    scanf("%d", &b);

    if(a>b)
        printf("max : %d\nMin : %d", a, b);
    else if(a<b)
        printf("max : %d\nMin : %d", b, a);
    else printf("Equal.");
}

void ParCount()
{
    int a[32];
    printf("Enter array of 32 integers.");
    for(int i= 0; i<32; i++)
        scanf("%d", &a[i]);
    
    int n = 0;
    int x = 32;
    for(int i = 0; i < x; i++){
        if(a[i]%2==0)
            n++;
    }
        
    printf("Even %d\n Odd %d\n", n, x - n);
}

void sqLess()
{
    printf("Enter number.");
    int n;
    scanf("%d", &n);
    for(int i = 0; i*i < n; i++)
        printf("%d\n", i*i);
    
}

void composite()
{
    printf("Enter number.");
    int n = 0;
    scanf("%d", &n);

    for(int i = 2; i <= n; i++)
        for(int j = 2; j < i; j++)
            if(i%j==0){
                printf("%d\n", i);
                break;
            }
}

int FP()
{
    printf("Enter bound.");
    int a;
    scanf("%d", &a);

    printf("Enter other bound.");
    int b;
    scanf("%d", &b);

    if(a==b){
        printf("No possible values.");
        return 1;
    }
    if(a>b){
        int temp = 0;
        temp = a;
        a = b;
        b = temp;
    }

    int t = 1, t_p = 0, t_n = 0;
    for(int i = 0; t_n<b; i++){
        t_n = t_p + t;
        t_p = t;
        t = t_n;
        if(t_n>a)
            printf("%d\n", t_n);
    }

    return 0;
}

void PinFib()
{
    printf("Enter number of terms.");
    int n;
    scanf("%d", &n);
    int FibPin[n];
    int FPsq[n];

    FibPin[0] = 0;
    FibPin[1] = 1;
    FPsq[0] = 0;
    FPsq[1] = 1;
    
    for(int i = 2; i<n; i++){
        FibPin[i] = FibPin[i - 1] + FibPin[i - 2];
        FPsq[i] = FibPin[i]*FibPin[i];
    }
}

#define T unsigned long long int
#include <math.h>
void Taxicab()
{
    T k;
    int count = 0;
    for(T i = 1; i <= 45000; i++){
        for(T j = 1; j < i; j++){
            if(pow(j, 3)>i)
                break;
                
            k = i - pow(j, 3);
            T p;
            for(p = 1; pow(p, 3)<=k; p++){
                if (pow(p, 3)==k)
                    count++;
            }
            if(count==2) 
                printf("%llu = %llu^3 + %llu^3\n", i, j, p);   
        }

        count = 0;
    }
}

int main()
{
    printf("Enter \n1 - Cubic\n2 - Min-Max\n3 - Parity Counter\n4 - Squares Less than\n5 - Composites\n6 - FP series within interval\n7 - Squares of Fibonacci-Pingala numbers\n8 - Taxicab\n");
    int c;
    scanf("%d",  &c);
    switch(c){
        case 1 : Cubic();;
        break;
        case 2 : minmax();
        break;
        case 3 : ParCount();
        break;
        case 4 : sqLess();
        break;
        case 5 : composite();
        break;
        case 6 : FP();
        break;
        case 7 : PinFib();
        break;
        case 8 : Taxicab();
        break;
    }
    return 0;
}