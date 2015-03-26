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
void function_f3();

/*************************
 * Function Pointers
************************/
void (*f1)();
void (*f2)();
void (*f3)();

int main()
{
	RunQ = new_Queue();

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
	//loop
		//x++
		//v(mutex)
		//print(x)
}

void f2()
{
	//loop
		//x++
		//v(mutex)
		//print(x)
}
