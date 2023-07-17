
#include <stdio.h>
#include <math.h>

int main()
{
    int ones[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
    int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

    long int count = 0;
    for(int i = 1; i < 1000; i++){
        //hundreds
        count += ones[(i/100)];
        if(i >= 100){
            count += 7; //"hundred"
            if(i%100 != 0) count += 3; //"and"
        }
        //tens
        if((i%100)/10 == 1){
            switch (i%10){
                case 0 : count += 3;
                break;
                case 1 : 
                case 2 : count += 6; 
                break;
                case 3 :
                case 4 :
                case 8 :
                case 9 : count += 8;
                break;
                case 5 :
                case 6 : count += 7;
                case 7 : count += 9;

            }
        } 
        else count += tens[(i%100)/10] + ones[i%10];
    }
    count += 11; //one thousand
    printf("%ld", count);
}