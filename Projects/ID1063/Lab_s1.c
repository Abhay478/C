
#include <stdio.h>

int main(){
    //Exercise 1
    printf("The escape character is typically \\.\n");
    printf("We said \"Hello World\", and all was good!\n");
    printf("%% can be printed by using %%%% inside the printf command.\n");

    //Exercise 2
    int n = 10;
    int choose_2 = (n*(n-1))/2;
    double miles = n/1.6;
    double centimetres = n * 2.54;
    printf("choose 2 : %d \nmiles : %.2f \ncentimetres : %.2f \n", choose_2, miles, centimetres);

    //Exercise 3
    double a = 8.14;
    printf("float : %g\nint : %d \nchar : %c \n", a, (int)a, (int)a);
    int x = 128;

    return x;
}