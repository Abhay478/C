#include <stdio.h>

int len(char * s)
{
    int i;
    for(i = 0; s[i] != 0; i++);
    return i;
}

int main()
{
    int multiplicand[100],multiplier[100];
    int out[200]={0};
    int i,j,tmp;
    char s1[101],s2[101];
    scanf("%s",s1);
    scanf("%s",s2);
    int l1 = len(s1);
    int l2 = len(s2);
    for(i = l1-1,j=0;i>=0;i--,j++)
    {
        multiplicand[j] = s1[i]-'0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        multiplier[j] = s2[i]-'0';
    }
    for(i = 0;i < l2;i++)
    {
        for(j = 0;j < l1;j++)
        {
            out[i+j] += multiplier[i]*multiplicand[j];
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        tmp = out[i]/10;
        out[i] = out[i]%10;
        out[i+1] = out[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0;i--)
    {
        if(out[i] > 0)
            break;
    }
    printf("Product : ");
    for(;i >= 0;i--)
    {
        printf("%d",out[i]);
    }
    return 0;
}