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

#include "q.h"
#include "threads.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

/********************
 * Gobal Variables
 ********************/
Queue RunQ;
int globalInt = 0;

/********************
 * Function Prototypes
 ********************/
void f1();
void f2();


int main()
{
	struct TCB_t *newTCB;

	/*************************
	 * Function Pointers
	 ************************/
	void (*f1)();
	void (*f2)();

	/*************************
	 * Initialize Threads
	 ************************/
	start_thread(f1, newTCB);
	start_thread(f2, newTCB);

	run();
}

void f1()
{
	int localInt = 0;
	while(1)
	{
		printf("f1 %d", localInt);
		yield();
		localInt++;

		printf("f2 %d", localInt);
		yield();

		sleep();
	}
}

void f2()
{
	int localInt = 0;

	while(1)
	{
		printf("f2 %d", localInt);
		yield();
		localInt++;

		printf("f1 %d", localInt);

		yield();

		sleep();
	}
}

