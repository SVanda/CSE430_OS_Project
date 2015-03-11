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

#include <iostream>
#include <string>
#include <iomanip>

#include "TCB.h"
#include <ucontext.h>

//using namespace std;

struct TCB_t
{
	ucontext_t context;
	struct TCB_t *next;
	struct TCB_t *previous;
};

class Queue{
	private:
		struct TCB_t *head;
		int numElements;
	public:
		Queue();
		TCB_t* NewItem(ucontext_t context);
		void DeleteItem();
		void RotateHead();
		void InitQueue(struct TCB_t *head);
		void PrintQueue();
		void AddQueue(struct TCB_t *head, struct TCB_t *item);
		TCB_t* DelQueue(struct TCB_t *head);
		void RotateQ(struct TCB_t *head);
};

Queue RunQ; // global Queue to be used

/* Constructor */
Queue::Queue()
{
	numElements = 0;
}

/*returns a pointer to a new qelement*/
TCB_t* Queue::NewItem(ucontext_t context)
{
	TCB_t *new_item, *temp;
	new_item = new TCB_t;

	new_item->context = context;

	if (numElements == 0) { //first Queue element added
		head = new_item;
		InitQueue(head);
	} else {
		temp = head;
		for (int i = 0; i < numElements-1; i++) {
			temp = temp->next;
		}
		AddQueue(temp, new_item);
	}

	numElements++;

	PrintQueue();

	return new_item;
}

void Queue::DeleteItem()
{
	struct TCB_t *d_node;

	d_node = DelQueue(head);
	PrintQueue();
}

void Queue::RotateHead()
{
	RotateQ(head);
	PrintQueue();
}

/*creates an empty queue, pointed to by the variable head*/
void Queue::InitQueue(struct TCB_t *head)
{
	head->next = NULL;
	head->previous = NULL;
}

/*adds a queue item pointed to by "item" to the queue pointed to by head*/
void Queue::AddQueue(struct TCB_t *tempHead, struct TCB_t *item)
{
	tempHead->next = item;
	item->next = head;
	item->previous = tempHead;
	head->previous = item; 
}

/*deletes an item from head and returns a pointer to the deleted item*/
TCB_t* Queue::DelQueue(struct TCB_t *tempHead)
{
	TCB_t *deleteNode;

	deleteNode = tempHead;
	/* assuming rotating clockwise */
	head = deleteNode->next;
	(deleteNode->previous)->next = deleteNode->next;
	(deleteNode->next)->previous = deleteNode->previous;
	
	delete deleteNode;
	//deleteNode->previous = deleteNode->previous->previous;
	//deleteNode->previous->next = deleteNode->next;
	//deleteNode->next->previous = deleteNode->previous;
	numElements--;

	return deleteNode;
}

/*moves the head pointer to the next element in the queue*/
void Queue::RotateQ(struct TCB_t *tempHead)
{
	head = head->next;
}

void Queue::PrintQueue()
{
	struct TCB_t *temp;
	temp = head;

	cout << "Head = " << head->context << "\n";

	for (int i = 0; i < numElements; i++) {
		cout << "Item " << i+1 << " = " << temp->context << "\n";
		temp = temp->next;
	}
}
