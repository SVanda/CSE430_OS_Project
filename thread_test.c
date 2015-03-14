/************************************************
 * Operating Systems CSE 430
 * Project 2 - Threading program with non-preemptive scheduling.
 *
 * Copyright (c) 2015
 *      Sydney Vanda
 *      Brittney RUssell
 *
 *  Module Name:
 *      \file thread_test.cpp
 *
 *  Description:
 *      \brief Thread test program
 *
 *      This module will test the multithread logic
 *      to be implemented
 *
 *
 *
 ***********************************************/


#include <stdio.h>
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
	RunQ = new_Queue();

	f1 = function_f1;
	f2 = function_f2;

	/*************************
	 * Initialize Threads
	 ************************/
	start_thread(f1);
	start_thread(f2);
	run();
	return 0;
}

void function_f1()
{
	int localInt = 0;
	while(1)
	{
		printf("f1 %d\n", localInt);
		yield();
		localInt++;

		printf("global = %d\n", globalInt);
		printf("f2 %d\n", localInt);
		yield();

		sleep(1);
	}
}

void function_f2()
{
	int localInt = 0;

	while(1)
	{
		printf("f2 %d\n", localInt);
		yield();
		localInt++;

		printf("global = %d\n", globalInt);
		printf("f1 %d\n", localInt);

		yield();

		sleep(1);
	}
}
