// Queue Operations
#include<stdio.h>
#include<stdlib.h>
#include"tcb.h"

/**<
struct q{
	int data;
	struct q *next;
	struct q *prev;
};
*/

/**< struct q* NewItem(){//creates an empty node
	struct q *newNod = (struct q*)malloc(sizeof(struct q));
	return newNod;
}
 */
TCB_t* NewItem(){//creates an empty node
	TCB_t *newNode = (TCB_t*)malloc(sizeof(TCB_t));
	return newNode;
}

void InitQueue(TCB_t **start){//creates an empty node and point to it as 'head'
	/*if(*start==NULL){
		*start=NewItem();
		(*start)->next=NULL;
		(*start)->prev=NULL;
		printf("\n Initiated the Queue!");
		fflush(stdout);
	}else {
		printf("\n Queue already initiated!");
		fflush(stdout);
	}*/

	*start = NULL;
}

void AddQueue(TCB_t **head, TCB_t *item){//adds a new value into the queue
	/*if (*start == NULL)
	{
		InitQueue(&RunQ);
		//printf("\n First initiate the Queue!");
		//fflush(stdout);
	}
	if((*start)->next==NULL){
		TCB_t* new_node=*start;
		new_node->context = value->context;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		printf("\n Head added to the Queue ");
		fflush(stdout);
	}
	else{
		TCB_t *last = (*start)->prev;
		TCB_t* new_node=NewItem();
		new_node->context = value->context;
		new_node->next = *start;
		(*start)->prev = new_node;
		new_node->prev = last;
		last->next = new_node;
		printf("\n Element added to the Queue ");
		fflush(stdout);
	}*/

	TCB_t* temp = *head;
	if (temp == NULL) {
		*head = item;	
		(*head)->next = *head;
		(*head)->prev = *head;
	} else if (temp->next == temp) {		
		temp->next = item;
		temp->prev = item;
		item->next = temp;
		item->prev = temp;
	} else {
		//while (temp->next != *head)
		//	temp = temp->next;
		temp = temp->prev;
		item->next = temp->next;
		item->prev = temp;
		temp->next = item;
		(*head)->prev = item;
}
}

TCB_t* DelItem(TCB_t **head){
	/*TCB_t *temp1=*start;
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
	return temp1;*/

	TCB_t* del = *head;
	if (del == NULL)
		printf(" Empty Queue");
	
	if (del->next == del) {
		*head = NULL;
	} else {
		while (del->next != *head) {
			del = del->next;
		}
		del->prev->next = del->next;
		del->next->prev = del->prev;
	}
return del;

}

void RotateQ(TCB_t **start){
	(*start)=(*start)->next;
	return;
}


