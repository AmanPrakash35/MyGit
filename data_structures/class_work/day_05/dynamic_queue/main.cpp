/*
 * main.cpp
 *
 *  Created on: 29-Sep-2017
 *      Author: sunbeam
 */


#include<iostream>
using namespace std;

#include<queue>


enum menu_options{ EXIT, INSERT_ELE, DELETE_ELE };

int menu(void)
{
	int choice;


	cout << "<========== dynamic queue ==========> " << endl;
	cout << "0. exit" << endl;
	cout << "1. insert element" << endl;
	cout << "2. delete element" << endl;

	cout << "enter the choice: ";
	cin >> choice;

	return choice;

}

int main(void)
{
	int choice;
	int ele;
	queue<int> q;

	while(1)
	{
		choice = menu();
		switch( choice )
		{
		case EXIT: exit(0);

		case INSERT_ELE: //insert element into the queue
			cout << "enter the element: ";
			cin >> ele;

			q.push(ele);

			cout << ele << " is pushed into queue successfully..." << endl;

			break;

		case DELETE_ELE: //delete element into the queue
			if( !q.empty() )
			{
				cout << "deleted ele is: " << q.front() << endl;
				q.pop();
			}
			else
				cout << "queue underflow !!!" << endl;

			break;

		}//end of switch control block
	}
	return 0;
}




