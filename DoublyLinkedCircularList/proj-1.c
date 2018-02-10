//author: Akshay 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "q.h"

struct q* head=NULL;

int main(){

	int input=9;
	int item;
	struct q* temp;
	struct q* NewItem();
	void InitQueue(struct q **start);
	void AddQueue(struct q **start,int value);
	struct q* DelItem(struct q **start);
	void RotateQ(struct q **start);
	void printmenu();
	printmenu();

	do{
		printf("\n Your choice : ");
		fflush(stdout);
		scanf("%d", &input);

		switch (input){
		case 1:
			InitQueue(&head);
			break;
		case 2://add element
			printf("\n Enter element to add to the Queue: ");
			fflush(stdout);
			scanf("%d",&item);
			AddQueue(&head,item);
			break;

		case 3://delete head
			temp=DelItem(&head);
			if(temp!=NULL){
				printf("\n Deleted Item is: (%d)",temp->data);
				fflush(stdout);}
			break;

		case 4://display queue
			printf("\n Printing the Queue \n");
			fflush(stdout);
			temp=head;
			if(head==NULL){
				printf("\n Empty Queue \n");
				fflush(stdout);
			}
			else{
				while(temp->next!=head){
					printf("\t %d",temp->data);
					fflush(stdout);
					temp=temp->next;
				}printf("\t %d",temp->data);
			}
			break;

		case 5://rotate queue
			if(head!=NULL){
				RotateQ(&head);
				printf("\n Queue rotated one position to the left \n");
				fflush(stdout);}
			else{
				printf("\n Empty Queue \n");
				fflush(stdout);
			}
		break;
		case 6://print menu
			printmenu();
			break;
		case 0://exit
			free(head);
			break;
		default:
			printf("Unknown choice!!");
			fflush(stdout);
			break;

	}
}while(input!=0);
return 0;
}

void printmenu(){
	printf("Choose\t\tAction\n");
	printf("------\t\t------\n");
	printf("1\t\tInitiate the Queue\n");
	printf("2\t\tAdd Queue\n");
	printf("3\t\tDelete Queue\n");
	printf("4\t\tDisplay Queue\n");
	printf("5\t\tRotate Queue\n");
	printf("6\t\tDisplay Menu\n");
	printf("0\t\tExit\n");
	fflush(stdout);
}
