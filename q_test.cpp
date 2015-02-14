/**********************************************
 * q_test to test doubly linked circular Queue
 *
 * Operating Systems CSE 430
 * Project 1 - functions for a queues as doubly linked, circular lists
 * Sydney Vanda and Brittney Russell
 *
 ***********************************************/

#include "q.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int selection = 0;
	int data = 0;

	//Queue *qu = new Queue;
	Queue qu;
	struct Qelement *newElem;

	while(selection != 5)
	{
	printf("Queue Test\n");
	printf("1. Add Element\n 2. Delete Element\n 3. Rotate Head\n 4. Print Queue\n 5. Quit\n");

	printf("What option are you selecting?");
	cin >> selection;
	cin.ignore(20, '\n');


		switch(selection)
		{
		case 1:
			cout << "Data to add: \n";
			cin >> data;
			cin.ignore(20, '\n');

			newElem = qu.NewItem(data);
			break;

		case 2:
			printf("Delete Item.\n");
			qu.DeleteItem();
			break;

		case 3:
			printf("Rotate Head.\n");
			qu.RotateHead();
			break;

		case 4:
			printf("Printing Queue.\n");
			qu.PrintQueue();
			break;

		case 5:
			printf("Bye!");
			return -1;

		default:
			cout << "Not reaching case!\n";
			break;
		}
	}

}
