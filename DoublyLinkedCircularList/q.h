//author: Akshay
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct q{
	int data;
	struct q *next;
	struct q *prev;
};
struct q *tail=NULL;

struct q* NewItem(){//creates an empty node
	struct q *newNode=malloc(sizeof(struct q));
	return newNode;
}

void InitQueue(struct q **start){//creates an empty node and point to it as 'head'
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

void AddQueue(struct q **start,int value){//adds a new value into the queue
	if (*start == NULL)
	{
		printf("\n First initiate the Queue!");
		fflush(stdout);
	}else if((*start)->next==NULL){
		struct q* new_node=*start;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		printf("\n Head added to the Queue ");
		fflush(stdout);
	}
	else{
		struct q *last = (*start)->prev;
		struct q* new_node=NewItem();
		new_node->data = value;
		new_node->next = *start;
		(*start)->prev = new_node;
		new_node->prev = last;
		last->next = new_node;
		printf("\n Element added to the Queue ");
		fflush(stdout);
	}
}

struct q* DelItem(struct q **start){
	struct q *temp1=*start;
	if (*start == NULL)
	{printf(" Empty Queue");
	fflush(stdout);
	}
	else if(*start==(*start)->next) {
		printf("It's the last element in Queue, Queue is deleted");
		fflush(stdout);
		struct q *temp = NULL;
		*start=temp;
	}
	else{
		struct q *last = (*start)->prev;
		struct q *temp = *start;
		temp=temp->next;
		last->next=temp;
		temp->prev=last;
		*start=temp;
	}
	return temp1;
}

void RotateQ(struct q **start){
	(*start)=(*start)->next;
}

