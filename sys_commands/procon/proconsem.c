#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>
#define MAXITEM 3
#define BUFFERSIZE 3
sem_t empty;
sem_t full;
int in=0;
int out=0;
int buffer[BUFFERSIZE];
pthread_mutex_t mutex;
void *producer(void *pno){
	int item;
	for(int i=0;i<MAXITEM;i++){
		sem_wait(&empty);
		item = rand();
		pthread_mutex_lock(&mutex);
		buffer[in]=item;
		printf("Producer %d Insert item %d at %d \n",*((int *)pno),buffer[in],in);
		in = (in + 1)%BUFFERSIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}
void * consumer(void *cno){
	for(int i=0;i<MAXITEM;i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[out];
		printf("Consumer %d remove Item %d from %d\n",*((int *)cno),item,out);
		out = (out+1)%BUFFERSIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
		}
}
int main(){
	pthread_t pro[3],con[3];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty,0,BUFFERSIZE);
	sem_init(&full,0,0);
	int a[]={1,2,3,4,5};
	for(int i=0;i<3;i++)
		pthread_create(&pro[i],NULL,(void *)producer,(void *)&a[i]);
	for(int i=0;i<3;i++)
		pthread_create(&con[i],NULL,(void *)consumer,(void *)&a[i]);
	for(int i=0;i<3;i++)
		pthread_join(pro[i],NULL);
	for(int i=0;i<3;i++)
		pthread_join(con[i],NULL);
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
	return 0;
}