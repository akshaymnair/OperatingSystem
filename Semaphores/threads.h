#include"q.h"

	ucontext_t parent1;     // get a place to store the main context, for faking
	

void start_thread(void (*function)(void))
{ // begin pseudo code
	//   allocate a stack (via malloc) of a certain size (choose 8192)
	void* stack=(void *)malloc(sizeof(8192));
	//  allocate a TCB (via malloc)
	TCB_t *newT=NewItem();
	//TCB_t *newT;
	//  call init_TCB with appropriate arguments
	init_TCB(newT,function,stack,8192);
	//  call addQ to add this TCB into the “RunQ” which is a global header pointer
	//InitQueue(&head);
	AddQueue(&RunQ,newT);
	//end pseudo code
}

void run()
{   // real code
  // magic sauce
	getcontext(&parent1); 
	swapcontext(&parent1,&(RunQ->context));  // start the first thread
	//swapcontext(&parent,&(head->context));
}

void yield() // similar to run
{
	TCB_t * temp= RunQ;
	//rotate the run Q;
	RotateQ(&RunQ);
	//swap the context, from previous thread to the thread pointed to by RunQ
	swapcontext(&(temp->context),&(RunQ->context));
	
	
}


