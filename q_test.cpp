/**********************************************
 * q_test to test doubly linked circular Queue
 *
 * Operating Systems CSE 430
 * Project 1 - functions for a queues as doubly linked, circular lists
 * Sydney Vanda and Brittney Russell
 *
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "q.h"

int main()
{
	int selection = 0;
	int data = 0;

	Queue *qu = new Queue();

	printf("Queue Test\n\n");
	printf("1. Add Element\n 2. Delete Element\n 3. Rotate Head\n 4. Print Queue\n");

	printf("What option are you selecting?");
	scanf("%d", selection);

	switch(selection)
	{
	case 1:
		printf("Data to add: \n");
		scanf("%d\n", data);
		qu->NewItem(data);

	case 2:
		printf("Delete Item.\n");
		qu->DeleteItem();

	case 3:
		printf("Rotate Head.\n");
		qu->RotateHead();

	case 4:
		printf("Printing Queue.");
		qu->PrintQueue();

	case 5:
		printf("Delete Queue.");
		delete(qu);

	}

}
