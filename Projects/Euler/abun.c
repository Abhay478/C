
#include <stdio.h>
#include <stdlib.h>

int div_sum(int x)
{
    int sum = 0;
    int i;
    for(i = 1; i*i <= x; i++)
        if((x%i) == 0){
            sum += i;
            sum += x/i;
        }
    
    if(i*i == x) sum -= i;
    sum -= x;
    return sum;
}

int * get_ab()
{
    int * out = malloc(1);
    int count = 1;
    for(int i = 1; i < 28124; i++){
        if(div_sum(i) > i){
            out = realloc(out, (count + 1)*sizeof(int));
            out[count] = i;
            count++;
        }
    }
    out[0] = count;
    return out;
}

int sum_stuff(int * a)
{
    int sum = 0;
    for(int i = 1; i < 28123; i++){
        for(int j = 1; j <= a[0]; j++){
            for(int k = j; k <= a[0]; k++){
                if(i > a[j] && i - a[j] == a[k]) goto Fortysix;
            }
        }
        sum += i;
        printf("%d\n", i);
        Fortysix :
        continue;
    }
    return sum;
}

int main()
{
    int * stuff = get_ab();
    int out = sum_stuff(stuff);
    printf("%d\n", out);

    free(stuff);
    return 0;
}