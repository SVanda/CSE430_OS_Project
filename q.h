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
 * circular queue to solve re-buffering for dequeue operation, FIFO, both front
 * and rear pointers point to the beginnning of the array but still
 * added to rear and deleted from front double linked list = right side pointer
 * points to the next node address and left side pointer points to the previous
 * node address
 *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
//#include "TCB.h"

struct Qelement
{
	int context;
	struct Qelement *next;
	struct Qelement *previous;
};

typedef struct _Queue Queue;

// declaration of pointers to functions
typedef struct Qelement* (*fptrNewItem)(int context, Queue*);
typedef void (*fptrDeleteItem)(Queue*);
typedef	void (*fptrRotateHead)(Queue*);
typedef	void (*fptrInitQueue)(struct Qelement *head);
typedef	void (*fptrPrintQueue)(Queue*);
typedef	void (*fptrAddQueue)(struct Qelement *, struct Qelement *, Queue*);
typedef	struct Qelement* (*fptrDelQueue)(struct Qelement *, Queue*);
typedef	void (*fptrRotateQ)(Queue*);

typedef struct _Queue{
	int numElements;
	struct Qelement *head;
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
struct Qelement* Queue_NewItem(int context, Queue* qu);
void Queue_DeleteItem(Queue* qu);
void Queue_RotateHead(Queue* qu);
void Queue_InitQueue(struct Qelement *head);
void Queue_PrintQueue(Queue* qu);
void Queue_AddQueue(struct Qelement *head, struct Qelement *item, Queue* qu);
struct Qelement* Queue_DelQueue(struct Qelement *head, Queue* qu);
void Queue_RotateQ(Queue* qu);


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
struct Qelement* Queue_NewItem(int context, Queue* qu)
{
	int i;
	struct Qelement *new_item, *temp;
	new_item = (struct Qelement *)malloc(sizeof(struct Qelement));

	new_item->context = context;

	if (qu->numElements == 0) { //first Queue element added
		qu->head = new_item;
		qu->InitQueue(qu->head);
	} else {
		temp = qu->head;
		for (i = 0; i < qu->numElements-1; i++) {
			temp = temp->next;
		}
		qu->AddQueue(temp, new_item, qu);
	}

	qu->numElements++;

	qu->PrintQueue(qu);

	return new_item;
}


void Queue_DeleteItem(Queue* qu)
{
	struct Qelement *d_node;

	d_node = qu->DelQueue(qu->head, qu);
	qu->PrintQueue(qu);
}

void Queue_RotateHead(Queue* qu)
{
	qu->RotateQ(qu);
	qu->PrintQueue(qu);
}

/*creates an empty queue, pointed to by the variable head*/
void Queue_InitQueue(struct Qelement *head)
{
	head->next = NULL;
	head->previous = NULL;
}

/*adds a queue item pointed to by "item" to the queue pointed to by head*/
void Queue_AddQueue(struct Qelement *tempHead, struct Qelement *item, Queue* qu)
{
	tempHead->next = item;
	item->next = qu->head;
	item->previous = tempHead;
	qu->head->previous = item; 
}

/*deletes an item from head and returns a pointer to the deleted item*/
struct Qelement* Queue_DelQueue(struct Qelement *tempHead, Queue* qu)
{
	struct Qelement *deleteNode;

	deleteNode = tempHead;
	/* assuming rotating clockwise */
	qu->head = deleteNode->next;
	(deleteNode->previous)->next = deleteNode->next;
	(deleteNode->next)->previous = deleteNode->previous;
	
	free(deleteNode);
	qu->numElements--;

	return deleteNode;
}

/*moves the head pointer to the next element in the queue*/
void Queue_RotateQ(Queue* qu)
{
	qu->head = qu->head->next;
}

void Queue_PrintQueue(Queue* qu)
{
	int i;
	struct Qelement *temp;
	temp = qu->head;

	//printf("Head = %x\n", head->context.uc_mcontext);
	printf("Head = %d\n", qu->head->context);

	for (i = 0; i < qu->numElements; i++) {
		//printf("Item %d = %x\n", i+1, temp->context.uc_mcontext);
		printf("Item %d = %d\n", i+1, temp->context);
		temp = temp->next;
	}
}
