/************************************************
 * Operating Systems CSE 430
 * Project 3 - Implementing semaphores
 *
 * Copyright (c) 2015
 *      Sydney Vanda
 *      Brittney RUssell
 *
 *  Module Name:
 *      \file sem.h
 *
 *  Description:
 *      \brief Semaphore processing logic
 *
 ***********************************************/
#ifndef SEM_H_
#define SEM_H_

#include "threads.h"

typedef struct _Semaphore
{
	int count;
	Queue* queue;
}Semaphore;

void InitSem(Semaphore* sem, int value);
void P(Semaphore* sem);
void V(Semaphore* sem);

/***********************************************
* Initializes the value field with the specified
* value.
 ***********************************************/
void InitSem(Semaphore* semaphore, int value)
{
	semaphore->count = value;
}

/***********************************************
 * The P routine decrements the semaphore, and if
 * the value is less than zero then blocks the
 * process in the queue associated with the semaphore.
 ***********************************************/
void P(Semaphore* semaphore)
{
	ucontext_t *thisContext;
	struct TCB_t *DelQ_return;

	semaphore->count--;
	if (semaphore->count < 0) { //block operation
		thisContext = &(RunQ->head->context);
		DelQ_return = RunQ->DeleteItem(RunQ); //returns the RunQ head
		(semaphore->queue)->NewItem(semaphore->queue, DelQ_return); //add previous RunQ head to Sem Queue
		swapcontext(thisContext, &(RunQ->head->context));
	}
}

/***********************************************
The V routine increments the semaphore, and if the
value is 0 or negative, then takes a PCB out of
the semaphore queue and puts it into the run queue.
Note: The V routine also "yields" to the next
runnable process. //this is important.
***********************************************/
void V(Semaphore* semaphore)
{
	struct TCB_t *DelQ_return;

	semaphore->count++;
	if (semaphore->count <= 0) {
		DelQ_return = (semaphore->queue)->DeleteItem(semaphore->queue); //deletes head from SemQ 
		RunQ->NewItem(RunQ, DelQ_return); //add the SemQ head back to the RunQ (unblock)
	}
	yield();  //important
	sleep(1);
}


#endif /* SEM_H_ */
