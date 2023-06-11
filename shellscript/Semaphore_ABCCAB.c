#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s1, s2, s3;
int turn = 1;
int counter = 0;
//A B C C A B 
//A B C C A B..

void* A() {
	while(1) {
		sem_wait(&s1);
		usleep(400);
		printf("A");
		sem_post(&s2);
	}
}

void* B() {
	while(1){
		if(counter == 10)
			exit(0);
		sem_wait(&s2);
		usleep(400);
		printf("B");
		if(turn == 2) {
			turn = 1;
			counter++;
			sem_post(&s1);
			printf("\n");
		}
		else {
			sem_post(&s3);
			sem_wait(&s2);
			sem_post(&s3);
			sem_wait(&s2);
			turn = 2;
			sem_post(&s1);
		}
	}
}

void* C() {
	while(1){
		sem_wait(&s3);
		usleep(400);
		printf("C");
		sem_post(&s2);
		
	}
}

int main()
{
	sem_init(&s1, 1, 1);
	sem_init(&s2, 1, 0);
	sem_init(&s3, 1, 0);
	
	pthread_t t1, t2, t3;
	int i1, i2, i3;
	
	
	i1 = pthread_create(&t1, NULL, A, NULL);
	i2 = pthread_create(&t2, NULL, B, NULL);
	i3 = pthread_create(&t3, NULL, C, NULL);

	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);


}







