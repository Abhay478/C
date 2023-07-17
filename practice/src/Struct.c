
#include "my_header.h"

int main(){
        struct date{
            int day, month, year;
        };
        struct time{
            int hour, min, sec; 
        };
    struct DT{
        struct date d;
        struct time t;
    }now, *p_now;
    p_now = &now; 

    //now = {{12, 11, 2021}, {15, 14, 9}};
    
    now.d.day = 12;
    now.d.month = 11;
    now.d.year = 2021;
    now.t.hour = 14;
    now.t.min = 28;
    now.t.sec = 54;
    printf("Date %d/%d/%d \nTime %d:%d:%d\n\n%p", p_now->d.day, p_now->d.month, p_now->d.year, p_now->t.hour, p_now->t.min, p_now->t.sec, p_now);
    return 0;
}