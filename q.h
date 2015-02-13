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
		int numElements = 0;

		void AddQueue(struct Qelement *head, struct Qelement *item);
		Qelement* DelQueue(struct Qelement *head);
		void RotateQ(struct Qelement *head);
	public:
		Qelement* NewItem(int payload);
		Qelement* DeleteItem();
		void InitQueue(struct Qelement *head);
};

/*returns a pointer to a new qelement*/
Qelement* Queue::NewItem(int payload)
{
	Qelement *new_item;
	new_item = (struct qelement *)malloc(sizeof(struct qelement));

	new_item->payload = this.payload;

	if (numElements == 0) { //first Queue element added
		head = new_item;
		InitQueue(head);
	} else
		AddQueue(head, new_item);

	numElements++;

	PrintQueue();

	return new_item;
}

Qelement* Queue::DeleteItem()
{
	DelQueue(head);
	PrintQueue();
}

Qelement* Queue::RotateHead()
{
	RotateQ(head);
	PrintQueue();
}

/*creates an empty queue, pointed to by the variable head*/
void Queue::InitQueue(struct Qelement *head)
{
	head->next = NULL:
	head->previous = NULL;
}

/*adds a queue item pointed to by "item" to the queue pointed to by head*/
void Queue::AddQueue(struct Qelement *head, struct Qelement *item)
{
	head->next = item;
	item->previous = head;
	head = item;
}

/*deletes an item from head and returns a pointer to the deleted item*/
Qelement* Queue::DelQueue(&head)
{
	Qelement *deleteNode;

	deleteNode = head;
	/* assuming rotating clockwise */
	head = deleteNode->next;

	deleteNode->previous = deleteNode->previous->previous;
	deleteNode->previous->next = deleteNode->next;
	deleteNode->next->previous = deleteNode->previous;
}

/*moves the head pointer to the next element in the queue*/
void Queue::RotateQ(&head)
{
	head = head.next;
}


void Queue::PrintQueue()
{
	struct Qelement *temp;
	temp = head;

	for (int i = 0; i < numElements; i++) {
		printf("Item %d = %d", i+1, temp->next->payload);
		printf("\n");
		temp = temp->next;
	}
}
