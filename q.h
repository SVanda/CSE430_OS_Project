/*
Operating Systems CSE 430 
Project 1 - functions for a queues as doubly linked, circular lists
Sydney Vanda and Brittney Russell
2/10/15
*/

//circular queue to solve re-buffering for dequeue operation, FIFO, both front and rear
//pointers point to the beginnning of the array but still added to rear and deleted from front
//double linked list = right side pointer points to the next node address and left side pointer
//points to the previous node address 


#include <stdio.h>
#include <stdlib.h>

typedef struct Qelement
{
	int payload;
	struct qelement *next;
	struct qelement *previous;
};

class Queue{
	private:
		struct Qelement *head;
		int numElements; // in case needing to keep track
	public:
		Qelement* NewItem();
		void InitQueue(&head);
		void AddQueue(&head, item);
		Qelement* DelQueue(&head);
		void RotateQ(&head);
};

/*returns a pointer to a new qelement*/
Qelement* Queue::NewItem()
{
	Qelement *new_item;
	new_item = (struct qelement *)malloc(sizeof(struct qelement));
	new_item->payload = 0; //user input??
	new_item->next = NULL;
	new_item->previous = NULL;

	return new_item;
}

/*creates an empty queue, pointed to by the variable head*/
void Queue::InitQueue(struct Qelement *head)
{
	head = NewItem();
	head = this.head;
	head->next = NULL:
	head->previous = NULL;
	head->numElements = 0;
}

/*adds a queue item pointed to by "item" to the queue pointed to by head*/
void Queue::AddQueue(struct Qelement *head, struct Qelement *item)
{
	Struct Qelement *item, *temp;
	item = NewItem();
	item = this.item;
	//InitQueue(&head);
	
	head->next = item;
	
}

/*deletes an item from head and returns a pointer to the deleted item*/
Qelement* Queue::DelQueue(&head)
{

}

/*moves the head pointer to the next element in the queue*/
void Queue::RotateQ(&head)
{

}

