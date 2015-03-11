/************************************************
 * Operating Systems CSE 430
 * Project 2 - Threading program with non-preemptive scheduling.
 *
 * Copyright (c) 2015
 *      Sydney Vanda
 *      Brittney RUssell
 *
 *  Module Name:
 *      \file threads.h
 *
 *  Description:
 *      \brief Threads processing logic
 *
 *
 *
 *
 ***********************************************/
#ifndef THREADS_H_
#define THREADS_H_

#include "q.h"

void start_thread(void (*function)(void), TCB_t *TCB);
void run();
void yield();

void start_thread(void (*function)(void), TCB_t *TCB)
{
	/*******************************************
	* begin pseudo code:
	* allocate a stack (via malloc) of a certain size (choose 8192)
	* allocate a TCB (via malloc)
	* call init_TCB with appropriate arguments
	* call addQ to add this TCB into the “RunQ” which is a global header pointer
	* end pseudo code
	*******************************************/
//	TCB_t *TCB;
	int *stack;
	
	TCB = (TCB_t *)malloc(sizeof(TCB_t));
	if(!TCB)
		printf("Out of Memory! \n");

	stack = (int *)malloc(8192 * sizeof(int)); //stack is an array of 8192 ints
	init_TCB(TCB, function, stack, sizeof(stack));
	RunQ.newItem(TCB->context);
}

void run() 
{  
	ucontext_t parent;     // get a place to store the main context, for faking
	getcontext(&parent);   // magic sauce
	swapcontext(&parent, &(RunQ->conext));  // start the first thread
}

void yield() // similar to run
{
	TCB_t thisQueueContext = RunQ->context;
	RunQ.RotateHead(); //rotate the run Q
	swapcontext(thisQueue, RunQ->context); //swap the context, from previous thread to the thread pointed to by RunQ
}

#endif /* THREADS_H_ */
