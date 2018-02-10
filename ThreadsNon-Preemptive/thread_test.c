#include<stdio.h>
#include<conio.h>
#include"threads.h"

void f1();
void f2();
void f3();
void f4();
TCB_t *RunQ=NULL;

int main(){
	int i=0;
while(i++<100){
	start_thread(f1);
	run();
	start_thread(f2);
	start_thread(f3);
	start_thread(f4);

}
	return 0;
}
void f1(){
	printf("Inside function 1 \n");
}
void (*fp1)()=&f1;
void f2(){
	printf("Inside function 2 \n");
}
void (*fp2)()=&f2;
void f3(){
	printf("Inside function 3 \n");
}
void (*fp3)()=&f3;
void f4(){
	printf("Inside function 4 \n");
}
void (*fp4)()=&f3;
