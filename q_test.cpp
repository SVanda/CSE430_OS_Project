/************************************************
 * Operating Systems CSE 430
 * Project 1 - Circular doubly linked list
 *
 * Copyright (c) 2015
 *      Sydney Vanda
 *      Brittney RUssell
 *
 *  Module Name:
 *      \file q_test.cpp
 *
 *  Description:
 *      \brief Queue processing test
 *
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
	cout << "Queue Test\n";
	cout << " 1. Add Element\n 2. Delete Element\n 3. Rotate Head\n 4. Print Queue\n 5. Quit\n";

	cout << "Select Menu Option: ";
	cin >> selection;
	cin.ignore(20, '\n');


		switch(selection)
		{
		case 1:
			cout << "Data to add: ";
			cin >> data;
			cin.ignore(20, '\n');

			newElem = qu.NewItem(data);
			break;

		case 2:
			cout << "Delete Item.\n";
			qu.DeleteItem();
			break;

		case 3:
			cout << "Rotate Head.\n";
			qu.RotateHead();
			break;

		case 4:
			cout << "Printing Queue.\n";
			qu.PrintQueue();
			break;

		case 5:
			cout << "Bye!\n";
			return -1;

		default:
			cout << "Not reaching case!\n";
			return -1;
		}
	}

}
