// CSE 330 OS - Fall 2017
// Name:  Akshay Muraleedharan Nair Santhy
// mail:  amurale1@asu.edu
// ID:    1212981859
// ASU


#include<stdio.h>
#include<unistd.h>
#include"sem.h"
#define BUFFER 5

void producer1();
void producer2();
void consumer1();
void consumer2();
void consumer3();

SEM_t *empty;
SEM_t *full;
SEM_t *mutex;
int buff[BUFFER];
int in=0;
int out=0;


int main(){

	InitQueue(&RunQ);

	empty = (SEM_t *)malloc(sizeof(SEM_t));
	full =  (SEM_t *)malloc(sizeof(SEM_t));
	mutex=  (SEM_t *)malloc(sizeof(SEM_t));

	InitSem(empty, BUFFER);
	InitSem(full, 0);
	//InitSem(mutex,1);

	start_thread(producer1);
	
	start_thread(producer2);

	start_thread(consumer1);

	start_thread(consumer2);

	start_thread(consumer3); // this consumer should be bocked
	
	printf("\n");

	run();

	return 0;
}

void producer1() {
	if(buff[in]==0){
		while (1) {
		P(empty);
		//P(mutex);

		// Critical Section
		buff[in] = 1;		
		// Move to next buff
		printf("Producer1 at buffer[%d]: %d , ++Global = %d \n",in,buff[in],++global);
		printf("Current buffer values :\n");
		for(int i=0;i<BUFFER;i++)
		printf("| %d ", buff[i] ); 
		printf("\n\n");
		sleep(1);
		in = (in + 1) % BUFFER;	
		// End Critical Section
		//V(mutex);
		V(full);
	}
}else{
	printf("The producer 1 is out of order\n");
	sleep(1);
	main();
}

	return;
}

void producer2() {
	if(buff[in]==0){
	while (1) {
		P(empty);
		//P(mutex);
		// Critical Section
		buff[in] = 1;		
		// Move to next buff
		printf("Producer2 at buffer[%d]: %d , ++Global = %d \n",in,buff[in],++global);
		printf("Current buffer values :\n");
		for(int i=0;i<BUFFER;i++)
		printf("| %d ", buff[i] ); 
		printf("\n\n");
		sleep(1);
		in = (in + 1) % BUFFER;	
		// End Critical Section
		//V(mutex);
		V(full);
	}
}else{
	printf("The producer 2 is out of order\n");
	sleep(1);
	main();
}

	return;
}

void consumer1() {
	if(buff[out]==1){
	while (1) {
		P(full);
		//P(mutex);
		// Critical Section
		printf("Consumer1 at buffer[%d]: %d , --Global = %d \n",out,buff[in],--global);
		buff[out] = 0;	
		out = (out + 1) % BUFFER;	
		// END CS
		//V(mutex);
		printf("Current buffer values :\n");
		for(int i=0;i<BUFFER;i++)
		printf("| %d ", buff[i] ); 
		printf("\n\n");
		sleep(1);
		V(empty);
	}
}else{
	printf("The consumer 1 is out of order\n");
	sleep(1);
	main();
}

	return;
}

void consumer2() {
	if(buff[out]==1){
	while (1) {
		P(full);
		//P(mutex);
		// Critical Section
		printf("Consumer2 at buffer[%d]: %d , --Global = %d \n",out,buff[in],--global);
		buff[out] = 0;	
		out = (out + 1) % BUFFER;	
		// END CS
		//V(mutex);
		printf("Current buffer values :\n");
		for(int i=0;i<BUFFER;i++)
		printf("| %d ", buff[i] ); 
		printf("\n\n");
		sleep(1);
		V(empty);
	}
}else{
	printf("The consumer 2 is out of order\n");
	sleep(1);
	main();
}

	return;
}


void consumer3() {
	if(buff[out]==1){
	while (1) {
		P(full);
		//P(mutex);
		// Critical Section
		printf("Consumer3 at buffer[%d]: %d , --Global = %d \n",out,buff[in],--global);
		buff[out] = 0;	
		out = (out + 1) % BUFFER;	
		// END CS
		//V(mutex);
		printf("Current buffer values :\n");
		for(int i=0;i<BUFFER;i++)
		printf("| %d ", buff[i] ); 
		printf("\n\n");
		sleep(1);
		V(empty);
	}
}else{
	printf("The consumer 3 is out of order\n");
	sleep(1);
	main();
}

	return;
}
