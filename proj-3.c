/************************************************
 * Operating Systems CSE 430
 * Project 3 - Implementing Semaphores
 *
 * Copyright (c) 2015
 *      Sydney Vanda
 *      Brittney RUssell
 *
 *  Module Name:
 *      \file proj-3.c
 *
 *  Description:
 *      \brief program to test implementation for
 *      semaphores
 *
 ***********************************************/

#include "threads.h"

/********************
 * Gobal Variables
 ********************/
Queue* RunQ;
int globalInt = 0;

/********************
 * Function Prototypes
 ********************/
void function_f1();
void function_f2();

/*************************
 * Function Pointers
************************/
void (*f1)();
void (*f2)();

int main()
{
	struct Semaphore *mutex; //global??
	
	RunQ = new_Queue();
	mutex->queue = new_Queue();

	InitSem(mutex, 0); //initialize value of mutex semaphore to 0??

	f1 = function_f1;
	f2 = function_f2;

	/*************************
	 * Initialize Threads
	 ************************/
	start_thread(f1);
	start_thread(f2);
	run(); //starts the first thread
	return 0;
}

void f1()
{
	while(1) {
		P(mutex);
		globalInt++;
		printf("F1 x = %d\n", x);
		V(mutex);
		printf("F1 end x = %d\n", x);
	}
}

void f2()
{
	while(1) {
		P(mutex);
		globalInt++;
		printf("F2 x = %d\n", x);
		V(mutex);
		printf("F2 end x = %d\n", x);
	}
}
