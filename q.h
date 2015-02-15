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

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
struct Qelement
{
	int payload;
	struct Qelement *next;
	struct Qelement *previous;
};

class Queue{
	private:
		struct Qelement *head;
		int numElements;
	public:
		Queue();
		Qelement* NewItem(int payload);
		void DeleteItem();
		void RotateHead();
		void InitQueue(struct Qelement *head);
		void PrintQueue();
		void AddQueue(struct Qelement *head, struct Qelement *item);
		Qelement* DelQueue(struct Qelement *head);
		void RotateQ(struct Qelement *head);
};

/* Constructor */
Queue::Queue()
{
	numElements = 0;
}

/*returns a pointer to a new qelement*/
Qelement* Queue::NewItem(int payload)
{
	Qelement *new_item, *temp;
	new_item = new Qelement;

	new_item->payload = payload;

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
	struct Qelement *d_node;

	d_node = DelQueue(head);
	PrintQueue();
}

void Queue::RotateHead()
{
	RotateQ(head);
	PrintQueue();
}

/*creates an empty queue, pointed to by the variable head*/
void Queue::InitQueue(struct Qelement *head)
{
	head->next = NULL;
	head->previous = NULL;
}

/*adds a queue item pointed to by "item" to the queue pointed to by head*/
void Queue::AddQueue(struct Qelement *tempHead, struct Qelement *item)
{
	tempHead->next = item;
	item->next = head;
	item->previous = tempHead; 
}

/*deletes an item from head and returns a pointer to the deleted item*/
Qelement* Queue::DelQueue(struct Qelement *tempHead)
{
	Qelement *deleteNode;

	deleteNode = tempHead;
	/* assuming rotating clockwise */
	head = deleteNode->next;
	deleteNode->previous->next = deleteNode->next;
	(deleteNode->next)->previous = deleteNode->previous;
	

	//deleteNode->previous = deleteNode->previous->previous;
	//deleteNode->previous->next = deleteNode->next;
	//deleteNode->next->previous = deleteNode->previous;

	return deleteNode;
}

/*moves the head pointer to the next element in the queue*/
void Queue::RotateQ(struct Qelement *head)
{
	head = head->next;
}


void Queue::PrintQueue()
{
	struct Qelement *temp;
	temp = head;

	for (int i = 0; i < numElements; i++) {
		cout << "Item " << i+1 << " = " << temp->payload << "\n";
		temp = temp->next;
	}
}
