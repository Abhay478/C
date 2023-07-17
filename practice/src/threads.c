#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdatomic.h>
atomic_int i = 0;
pthread_mutex_t lock;

void * f1(void * vargs){
    for(int j = 0; j < 100; j++){
        pthread_mutex_lock(&lock);
        i++;
        printf("1 : %d\n", i);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void * f2(void * vargs){
    for(int j = 0; j < 10; j++){

        pthread_mutex_lock(&lock);
        i++;
        printf("2 : %d\n", i);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(){
    pthread_t t1, t2;
    pthread_create(&t2, NULL, f2, NULL);
    pthread_create(&t1, NULL, f1, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}