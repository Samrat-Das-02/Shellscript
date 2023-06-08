/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<time.h>
// #define items 5
#define size 10

sem_t empty;
sem_t full;
int in=0;
int out=0;
int buffer[size];
pthread_mutex_t mutex;
void* producer(void* pno){
    int item;
    for(int i=0;i<size;i++){
        item=rand()%100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in]=item;
        // printf("Producer %d: produce item %d at %d\n",*((int*)pno),buffer[in],in);
        printf("Producer: produce item %d at %d\n",buffer[in],in);
        in=(in+1)%size;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        //sleep(2);
    }
}
void* consumer(void* cno){
    for(int i=0;i<size;i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item=buffer[out];
        // printf("Consumer %d: remove item %d from %d\n",*((int*)cno),item,out);
        printf("Consumer:removed item %d from %d\n",item,out);
        out=(out+1)%size;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
int main()
{
    pthread_mutex_init(&mutex,NULL);
    sem_init(&empty,0,size);
    sem_init(&full,0,0);
    pthread_t pro,con;
    // pthread_t pro[5],con[5];
    pthread_create(&pro,NULL,(void*)producer,NULL);
    pthread_create(&con,NULL,(void*)consumer,NULL);
    // int a[5]={1,2,3,4,5};
    // for(int i=0;i<5;i++){
    //     pthread_create(&pro[i],NULL,(void*)producer,(void*)&a[i]);   
    // }
    // for(int i=0;i<5;i++){
    //     pthread_create(&con[i],NULL,(void*)consumer,(void*)&a[i]);   
    // }
    
    pthread_join(pro,NULL);
    // for(int i=0;i<5;i++){
    // }
    // for(int i=0;i<5;i++){
    pthread_join(con,NULL);
    // }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}