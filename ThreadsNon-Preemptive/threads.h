#include"q.h"
void start_thread(void (*function)(void))
{ // begin pseudo code
	//   allocate a stack (via malloc) of a certain size (choose 8192)
	void* stack=(void *)malloc(sizeof(8192));
	//  allocate a TCB (via malloc)
	TCB_t *new=NewItem();
	//  call init_TCB with appropriate arguments
	init_TCB(new,*function,stack,sizeof(stack));
	//  call addQ to add this TCB into the “RunQ” which is a global header pointer
	AddQueue(&head,new->context);
	//end pseudo code
}

void run()
{   // real code
	ucontext_t parent;     // get a place to store the main context, for faking
	getcontext(&parent);   // magic sauce
	swapcontext(&parent, &(RunQ->conext));  // start the first thread
}

void yield() // similar to run
{
	//rotate the run Q;
	RotateQ(&head);
	//swap the context, from previous thread to the thread pointed to by RunQ
}

