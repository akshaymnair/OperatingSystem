#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"tcb.h"

/*struct q{
	int data;
	struct q *next;
	struct q *prev;
};*/
TCB_t *head=NULL;
TCB_t *tail=NULL;

TCB_t* NewItem(){//creates an empty node
	TCB_t *newNode=malloc(sizeof(TCB_t));
	return newNode;
}

void InitQueue(TCB_t **start){//creates an empty node and point to it as 'head'
	if(*start==NULL){
		*start=NewItem();
		(*start)->next=NULL;
		printf("\n Initiated the Queue!");
		fflush(stdout);
	}else {
		printf("\n Queue already initiated!");
		fflush(stdout);
	}
}

void AddQueue(TCB_t **start,ucontext_t context){//adds a new value into the queue
	if (*start == NULL)
	{
		printf("\n First initiate the Queue!");
		fflush(stdout);
	}else if((*start)->next==NULL){
		TCB_t* new_node=*start;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		printf("\n Head added to the Queue ");
		fflush(stdout);
	}
	else{
		TCB_t *last = (*start)->prev;
		TCB_t* new_node=NewItem();
		new_node->data = value;
		new_node->next = *start;
		(*start)->prev = new_node;
		new_node->prev = last;
		last->next = new_node;
		printf("\n Element added to the Queue ");
		fflush(stdout);
	}
}

TCB_t* DelItem(TCB_t **start){
	TCB_t *temp1=*start;
	if (*start == NULL)
	{printf(" Empty Queue");
	fflush(stdout);
	}
	else if(*start==(*start)->next) {
		printf("It's the last element in Queue, Queue is deleted");
		fflush(stdout);
		TCB_t *temp = NULL;
		*start=temp;
	}
	else{
		TCB_t *last = (*start)->prev;
		TCB_t *temp = *start;
		temp=temp->next;
		last->next=temp;
		temp->prev=last;
		*start=temp;
	}
	return temp1;
}

void RotateQ(TCB_t **start){
	(*start)=(*start)->next;
}

