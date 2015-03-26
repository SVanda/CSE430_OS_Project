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


struct Semaohore_t
{
	int count;
	//Qtype? points to element of the queues
};

void InitSem(semaphore, value);
void P(semaphore);
void V(semaphore);


/***********************************************
* Initializes the value field with the specified
* value.
 ***********************************************/
void InitSem(semaphore, value)
{
	//semaphore.count = vlue
}

/***********************************************
 * The P routine decrements the semaphore, and if
 * the value is less than zero then blocks the
 * process in the queue associated with the semaphore.
 ***********************************************/
void P(semaphore)
{
	//semaphore.count --
	//if count < 0
		//this = runq
		//delQ
		//addQ(semaphore.q, this)
		//swap_context(this, runq.context);
}

/***********************************************
The V routine increments the semaphore, and if the
value is 0 or negative, then takes a PCB out of
the semaphore queue and puts it into the run queue.
Note: The V routine also "yields" to the next
runnable process. //this is important.
***********************************************/
void V(semaphore)
{
	//semaphore.count ++
	//if count <= 0
		//addQ(runQ,delQ(s.q));
		//yeild()  //important
}


#endif /* SEM_H_ */
