/**********************************************
 * q_test to test doubly linked circular Queue
 *
 * Operating Systems CSE 430
 * Project 1 - functions for a queues as doubly linked, circular lists
 * Sydney Vanda and Brittney Russell
 *
 ***********************************************/
#include "q.h"

void main()
{
	int selection = 0;
	int data = 0;

	printf("Queue Test\n\n");
	printf("1. Add Element\n 2. Delete Element\n 3. Rotate Head\n 4. Print Queue\n");

	printf("What option are you selecting?");
	scanf("%d", selection);

	switch(selection)
	{
	case 1:
		printf("Data to add: \n");
		scanf("%d\n", data);
		Queue::NewItem(data);

	case 2:
		printf("Delete Item.\n");
		Queue::DeleteItem();

	case 3:
		printf("Rotate Head.\n");
		Queue::RotateHead();

	case 4:
		printf("Printing Queue.");
		Queue::PrintQueue();


	}
}
