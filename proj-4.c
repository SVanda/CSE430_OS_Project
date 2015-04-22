/************************************************
 * Operating Systems CSE 430
 * Project 4 - Readers and Writers
 *
 * Copyright (c) 2015
 *      Sydney Vanda
 *      Brittney RUssell
 *
 *  Module Name:
 *      \file proj-4.c
 *
 *  Description:
 *      \Readers and Writers problem with semaphores
 * 	Addressing readers/writers version 1: Reader's Preference
 *	In order to test the code - an array was created with 3 values (initially 1,2,3)
 * 	These values were read from the array, and upon a write, every value in the array was 
 *	multiplied by 4 to indicate a write was made. 
 *	Thread order of 3 readers and 2 writers are printed at the beginning once run along with
 *	function pointers of each thread for convenience and understanding (the function pointer
 *	for each thread is printed with each array as well for easy debugging).
 *
 ***********************************************/

#include "sem.h"

/********************
 * Gobal Variables
 ********************/
Queue* RunQ;
int globalInt = 0;

Semaphore* rsem; //<---0
Semaphore* wsem; //<---0
Semaphore* mutex; //<---1

int rc = 0; //reader count
int rwc = 0; //reader waiting count
int wwc = 0; //writer waiting count
int wc = 0; //write count
int test[3] = {1,2,3};
int read = 1;
int write = 1;

/********************
 * Function Prototypes
 ********************/
void reader();
void writer();

/*************************
 * Function Pointers
************************/
void (*r1)();
void (*r2)();
void (*r3)();
void (*w1)();
void (*w2)();

int main()
{	
	RunQ = new_Queue();

	mutex = (Semaphore*)malloc(sizeof(Semaphore));
	mutex->queue = new_Queue();
	InitSem(mutex, 1);

	rsem = (Semaphore*)malloc(sizeof(Semaphore));
	rsem->queue = new_Queue();
	InitSem(rsem,0);

	wsem = (Semaphore*)malloc(sizeof(Semaphore));
	wsem->queue = new_Queue();
	InitSem(wsem,0);

	r1 = reader;
	r2 = reader;
	r3 = reader;
	w1 = writer;
	w2 = writer;

	/*************************
	 * Initialize Threads
	 *************************/
	start_thread(r1);
	start_thread(w1);
	start_thread(w2);
	start_thread(r2);
	start_thread(r3);

	run(); //starts the first thread
	return 0;
}

void reader()
{
 printf("----Reader %d: %p----\n", read, RunQ->head);
 read++;
	
 while(1){
	// Reader enter
	P(mutex);	
	if(wwc>0 || wc>0) {
		rwc++;
		V(mutex);
		P(rsem);
		rwc--;
	}
	
	rc++;
	if(rwc>0)
		V(rsem);
	else
		V(mutex);


	//CS - read occurs here
	printf("Reader %p\n", RunQ->head);
	printf("Reading array: %d %d %d\n", test[0], test[1], test[2]);

	// Reader exit
	P(mutex);
	rc--;
	if(rc==0 && wwc>0)
		V(wsem);
	else
		V(mutex);
 }	
}

void writer()
{
 int i;
 printf("----Writer %d: %p----\n", write, RunQ->head);
 write++;

  while(1) {
	// Writer enter
	P(mutex);
	if(rc>0 || wc>0) {
		wwc++;
		V(mutex);
		P(wsem);
		wwc--;
	}
	
	wc++;
	V(mutex);


	//CS - write occurs here
	printf("Writer %p\n", RunQ->head);
	for (i = 0; i < 3; i++) {
		test[i] = test[i] * 4;
	}
	printf("Writing array: %d %d %d\n", test[0], test[1], test[2]);

	// Writer exit
	P(mutex);
	wc--;
	if(rwc>0)
		V(rsem);
	else {
		if(wwc>0)
			V(wsem);
		else
			V(mutex);
	}
 }
}

