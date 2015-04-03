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

//#include "util.h"
#include "sem.h"

/********************
 * Gobal Variables
 ********************/
Queue* RunQ;
int globalInt = 0;

struct Semaphore mutex;

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
	RunQ = new_Queue();
	mutex.queue = new_Queue();

	InitSem(mutex, 0);

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

//Function 1 & 2 are for Method 1

void function_f1()
{
	int f1_local = 0;

	while(1) {
		P(mutex);

		printf("In F1 CS\n");
		globalInt++;
		f1_local++;
		printf("F1 global = %d\n", globalInt);
		printf("F1 local = %d\n", f1_local);
		sleep(1);

		V(mutex);

		printf("F1 out of CS\n");
		sleep(1);
	}
}

void function_f2()
{
	int f2_local = 0;

	while(1) {
		P(mutex);

		printf("In F2 CS\n");
		globalInt++;
		f2_local++;
		printf("F2 global = %d\n", globalInt);
		printf("F2 local = %d\n", f2_local);
		sleep(1);

		V(mutex);

		printf("F2 out of CS\n");
		sleep(1);
	}
}
