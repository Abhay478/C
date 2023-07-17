/*
Dec 29th.

Roll Number:CS21BTECH11001
Name: Abhay Shankar K

 */
#include <stdio.h>
void Shift(int n, char s[20])
{
    for(int i = 0; i < 20; i++)
        s[i] += n;
    
    
}
int main()
{
    
    char str[20];
    int sh;
    scanf("%s", str);
    scanf("%d", &sh);

    Shift(sh, str);
    printf("%s", str);
    
    
    return 0;
    

}