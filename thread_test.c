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
	f3 = function_f3;

	/*************************
	 * Initialize Threads
	 ************************/
	start_thread(f1);
	start_thread(f2);
	start_thread(f3);
	run(); //starts the first thread
	return 0;
}

void function_f1()
{
	int localInt = 0, i;

	while(1)
	{
		//for (i = 0; i < 4; i++) {
			printf("f1 global = %d\n", globalInt);
			printf("f1 %d\n", localInt);
			localInt++;
		//}

		globalInt++;

		sleep(1);
		yield(); //context switch
	}
}

void function_f2()
{
	int localInt = 0, i;

	while(1)
	{
		//for (i = 0; i < 4; i++) {
			printf("f2 global = %d\n", globalInt);	
			printf("f2 %d\n", localInt);
			localInt++;
		//}

		globalInt++;

		sleep(1);
		yield(); //context switch
	}
}

void function_f3()
{
	int localInt = 0, i;

	while(1)
	{
		//for (i = 0; i < 4; i++) {
			printf("f3 global = %d\n", globalInt);	
			printf("f3 %d\n", localInt);
			localInt++;
		//}

		globalInt++;

		sleep(1);
		yield(); //context switch
	}
}
