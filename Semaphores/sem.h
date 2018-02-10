#include "threads.h"
#include <unistd.h>

typedef struct SEM_t {
     TCB_t *SemQ;
     int count;
} SEM_t;


void InitSem(SEM_t* sem, int c) {
	sem->SemQ = NULL;
	sem->count = c;
}

void P(SEM_t* sem) {
	if (sem->count > 0)
		sem->count--;
	
	else{
		TCB_t *current = DelItem(&RunQ);
		AddQueue(&(sem->SemQ), current);
		swapcontext(&(current->context), &(RunQ->context));
	}
}

void V(SEM_t* sem) {
	sem->count++;
	if (sem->SemQ != NULL) {
		AddQueue(&RunQ, DelItem(&(sem->SemQ)));
	}
	yield();
}