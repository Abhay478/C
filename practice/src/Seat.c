
#include <stdio.h>
#include <stdlib.h>

#include <stddef.h>


struct Candidate{
    char name[20];
    int marks;
    int rank;
};
void arrange(struct Candidate *I_list, const int I_no_cand);

void arrange(struct Candidate *I_list, const int I_no_cand){

    struct Candidate temp;
    int m, n;
    for(int i = 0; i < I_no_cand; i++){
        m = I_list[i].marks;
        for(int j = i; j < I_no_cand; j++){
            if(I_list[j].marks > m){
                m = I_list[j].marks;
                n = j;
            }
        }
        temp = I_list[i];
        I_list[i] = I_list[n];
        I_list[n] = temp;
    }

    for(int k = 0; k < I_no_cand; k++)
        I_list[k].rank = k+1;
}

int main(){
    int no_cand;

    printf("Enter number of candidates.");
    scanf("%d", &no_cand);

    struct Candidate *list = malloc(no_cand*sizeof(struct Candidate));

    for(int i = 0; i < no_cand; i++){
        printf("\nEnter name of candidate %d ", i+1);
        scanf("%s", list[i].name);

        printf("\nEnter score of candidate %d ", i+1);
        scanf("%d", &(list[i].marks));
    }

    arrange(list, no_cand);
    

    printf("Rank \t Name \t Marks \n");

    for(int a = 0; a< no_cand; a++){
        printf("%d \t %s \t %d \n", list[a].rank, list[a].name, list[a].marks);
    }

    
    return 0;
}