/************************************************
 * Operating Systems CSE 430
 * Project 1 - Circular doubly linked list
 *
 * Copyright (c) 2015
 *      Sydney Vanda
 *      Brittney RUssell
 *
 *  Module Name:
 *      \file q.h
 *
 *  Description:
 *      \brief Queue processing logic
 *
 *
 * circular queue to solve re-buffering for dequeue
 * operation, FIFO, both front and rear pointers point
 * to the beginnning of the array but still added to
 * rear and deleted from front double linked list =
 * right side pointer points to the next node address
 * and left side pointer points to the previous node address
 *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "TCB.h"

//typedef struct _Queue Queue;

// declaration of pointers to funcions
typedef void (*fptrNewItem)(struct TCB_t *);
typedef void (*fptrDeleteItem)();
typedef	void (*fptrRotateHead)();
typedef	void (*fptrInitQueue)();
typedef	void (*fptrPrintQueue)();
typedef	void (*fptrAddQueue)(struct TCB_t *, struct TCB_t *);
typedef	struct TCB_t* (*fptrDelQueue)(struct TCB_t *);
typedef	void (*fptrRotateQ)();

typedef struct _Queue{
	int numElements;
	struct TCB_t *head;
	// interface for function
	fptrNewItem NewItem;
	fptrDeleteItem DeleteItem;
	fptrRotateHead RotateHead;
	fptrInitQueue InitQueue;
	fptrPrintQueue PrintQueue;
	fptrAddQueue AddQueue;
	fptrDelQueue DelQueue;
	fptrRotateQ RotateQ;
}Queue;

// forward declaration of Queue functions
Queue* new_Queue(); //constructor, sets pointer functions
void Queue_NewItem(struct TCB_t *new_item);
void Queue_DeleteItem();
void Queue_RotateHead();
void Queue_InitQueue();
void Queue_PrintQueue();
void Queue_AddQueue(struct TCB_t *head, struct TCB_t *item);
struct TCB_t* Queue_DelQueue(struct TCB_t *head);
void Queue_RotateQ();

extern Queue* RunQ; // global Queue

// function definitions
/*constructor, sets pointer functions*/
Queue* new_Queue()
{
	Queue* newQueue;
	/* setting up queue */
	newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->numElements = 0; //initially set number of elements to 0

	// allow access to Queue functions thru function pointers
	newQueue->NewItem = Queue_NewItem;
	newQueue->DeleteItem = Queue_DeleteItem;
	newQueue->RotateHead = Queue_RotateHead;
	newQueue->InitQueue = Queue_InitQueue;
	newQueue->PrintQueue = Queue_PrintQueue;
	newQueue->AddQueue = Queue_AddQueue;
	newQueue->DelQueue = Queue_DelQueue;
	newQueue->RotateQ = Queue_RotateQ;

	return newQueue; //after obj creation can access data members and function similar to C++ class inheritance
}

/*returns a pointer to a new qelement*/
void Queue_NewItem(struct TCB_t *new_item)
{
	int i;
	struct TCB_t *temp;

	if (RunQ->numElements == 0) { //first Queue element added
		RunQ->head = new_item;
		RunQ->InitQueue();
	} else {
		temp = RunQ->head->previous;
		RunQ->AddQueue(temp, new_item);
	}

	RunQ->numElements++;
	//RunQ->PrintQueue();
}


void Queue_DeleteItem()
{
	struct TCB_t *d_node;

	d_node = RunQ->DelQueue(RunQ->head);
	RunQ->PrintQueue();
}

void Queue_RotateHead()
{
	RunQ->RotateQ();
	RunQ->PrintQueue();
}

/*creates an empty queue, pointed to by the variable head*/
void Queue_InitQueue()
{
	RunQ->head->next = RunQ->head;
	RunQ->head->previous = RunQ->head;
}

/*adds a queue item pointed to by "item" to the queue pointed to by head*/
void Queue_AddQueue(struct TCB_t *tempHead, struct TCB_t *item)
{
	tempHead->next = item;
	item->next = RunQ->head;
	item->previous = tempHead;
	RunQ->head->previous = item; 
}

/*deletes an item from head and returns a pointer to the deleted item*/
struct TCB_t* Queue_DelQueue(struct TCB_t *tempHead)
{
	struct TCB_t *deleteNode;

	deleteNode = tempHead;
	/* assuming rotating clockwise */
	RunQ->head = deleteNode->next;
	(deleteNode->previous)->next = deleteNode->next;
	(deleteNode->next)->previous = deleteNode->previous;
	
	free(deleteNode);
	RunQ->numElements--;

	return deleteNode;
}

/*moves the head pointer to the next element in the queue*/
void Queue_RotateQ()
{
	if (RunQ->numElements > 1)
		RunQ->head = RunQ->head->next;
	else
		printf("No rotation!\n");
}

void Queue_PrintQueue()
{
	int i;
	struct TCB_t *temp;
	temp = RunQ->head;

	//printf("Thread Head= %x\n", RunQ->head);

	for (i = 0; i < RunQ->numElements; i++) {
		//printf("Item %d = %x\n", i+1, temp);
		temp = temp->next;
	}
}
