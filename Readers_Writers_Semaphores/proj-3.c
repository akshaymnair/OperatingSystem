// CSE 330 OS - Fall 2017
// Name:  Akshay Muraleedharan Nair Santhy
// mail:  amurale1@asu.edu
// ID:    1212981859
// ASU
// Project 3


#include<stdio.h>
#include<unistd.h>
#include"sem.h"

void writer1();
void writer2();

void reader1(); 
void reader2(); 
void reader3(); 
void reader4(); 


SEM_t *mutex;
SEM_t *w_sem;
int rc, wc;

int main(){

	InitQueue(&RunQ);
	rc = 0;
	wc = 0;

	w_sem =  (SEM_t *)malloc(sizeof(SEM_t));
	mutex=  (SEM_t *)malloc(sizeof(SEM_t));

	InitSem(w_sem, 1);
	InitSem(mutex,1);

	

	start_thread(reader1);
	start_thread(reader3);
	start_thread(reader2);
	start_thread(reader4);
	start_thread(writer1);
	
	start_thread(writer2);
	
	run();
	return 0;
}

void writer1(){															// Writer function

	if(rc > 0 || wc > 0){															// Writer function
		printf("\n Writer 1 came and waiting.. ");
		sleep(1);
		yield();
	}
	
		P(w_sem);														// if no one there, continue
		printf("\n Writer 1 entered Scratchpad.. ");										// if no writer in scratchpad go inside 
		sleep(1);
		wc++;
		printf("\n Writer 1 started writing.. ");
		sleep(1);

		//yield();
		
		wc--;
		printf("\n Writer 1 finished writing and exiting!! ");
		sleep(1);
		V(w_sem);
		
}

void writer2(){														// Writer function

	if(rc > 0 || wc > 0){														// Writer function
		printf("\n Writer 2 came and waiting.. ");
		sleep(1);
		yield();
	}
	
		P(w_sem);														// if no one there, continue
		printf("\n Writer 2 entered Scratchpad.. ");										// if no writer in scratchpad go inside 
		sleep(1);
		wc++;
		printf("\n Writer 2 started writing.. ");
		sleep(1);

		//yield();

		wc--;
		printf("\n Writer 2 finished writing and exiting!! ");
		sleep(1);
		V(w_sem);
	
}


void reader1(){											// reader function
	if(wc > 0){											// check if a writer is already using the scratchpad
		printf("\n Reader 1 came and waiting.. ");		// if so wait 
		sleep(1);
		yield();										// leave control to other functions to execute 
	}
	else{		
		printf("\n Reader 1 entered Scratchpad.. ");										// if no writer in scratchpad go inside 
		P(mutex);			
		rc++;
		if(rc == 1)
			P(w_sem);
		sleep(1);
		printf("\n Reader 1 Started reading.. ");
		V(mutex);									// leave control 

		P(mutex);
		rc--;
		printf("\n Reader 1 Exiting!!");
		sleep(1);

		if(rc == 0)
			V(w_sem);
		V(mutex);
	}
}

void reader2(){											// reader function
	if(wc > 0){											// check if a writer is already using the scratchpad
		printf("\n Reader 2 came and waiting.. ");		// if so wait 
		sleep(1);
		yield();										// leave control to other functions to execute 
	}
	else{		
		printf("\n Reader 2 entered Scratchpad.. ");										// if no writer in scratchpad go inside 
		P(mutex);			
		rc++;
		if(rc == 1)
			P(w_sem);
		sleep(1);
		printf("\n Reader 2 Started reading.. ");
		V(mutex);									// leave control 

		P(mutex);
		rc--;
		printf("\n Reader 2 Exiting!!");
		sleep(1);

		if(rc == 0)
			V(w_sem);
		V(mutex);
	}
}

void reader3(){											// reader function
	if(wc > 0){											// check if a writer is already using the scratchpad
		printf("\n Reader 3 came and waiting.. ");		// if so wait 
		sleep(1);
		yield();										// leave control to other functions to execute 
	}
	else{		
		printf("\n Reader 3 entered Scratchpad.. ");										// if no writer in scratchpad go inside 
		P(mutex);			
		rc++;
		if(rc == 1)
			P(w_sem);
		sleep(1);
		printf("\n Reader 3 Started reading.. ");
		V(mutex);									// leave control 

		P(mutex);
		rc--;
		printf("\n Reader 3 Exiting!!");
		sleep(1);

		if(rc == 0)
			V(w_sem);
		V(mutex);
	}
}

void reader4(){											// reader function
	if(wc > 0){											// check if a writer is already using the scratchpad
		printf("\n Reader 4 came and waiting.. ");		// if so wait 
		sleep(1);
		yield();										// leave control to other functions to execute 
	}
	else{		
		printf("\n Reader 4 entered Scratchpad.. ");										// if no writer in scratchpad go inside 
		P(mutex);			
		rc++;
		if(rc == 1)
			P(w_sem);
		sleep(1);
		printf("\n Reader 4 Started reading.. ");
		V(mutex);									// leave control 

		P(mutex);
		rc--;
		printf("\n Reader 4 Exiting!!");
		sleep(1);

		if(rc == 0)
			V(w_sem);
		V(mutex);
	}
}