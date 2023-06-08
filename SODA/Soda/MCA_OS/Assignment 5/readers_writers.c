
#include <stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<time.h>
#define turn 10
// #define items 5
// #define size 10
sem_t wrt;
pthread_mutex_t mutex;
int cnt=1;
int readerCount=0;

void* wrtr(void* arg){
    for(int i=0;i<turn;i++){
        sem_wait(&wrt);
        cnt*=2;
        printf("Writer modified counter to %d\n",cnt);
        sem_post(&wrt);
    }
}
void* rdr(void* arg){
    for(int i=0;i<turn;i++){
        pthread_mutex_lock(&mutex);
        readerCount++;
        if(readerCount==1){
            sem_wait(&wrt);
        }
        pthread_mutex_unlock(&mutex);
        //reading
        printf("Reader read counter as %d\n",cnt);
        pthread_mutex_lock(&mutex);
        readerCount--;
        if(readerCount==0){
            sem_post(&wrt);
        }
        pthread_mutex_unlock(&mutex);
            
    }
}
int main(){
    pthread_t reader,writer;
    pthread_mutex_init(&mutex,NULL);
    sem_init(&wrt,0,1);
    pthread_create(&reader,NULL,rdr,NULL);
    pthread_create(&writer,NULL,wrtr,NULL);
    pthread_join(reader,NULL);
    pthread_join(writer,NULL);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}