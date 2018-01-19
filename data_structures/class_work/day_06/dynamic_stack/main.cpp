/*
 * main.cpp
 *
 *  Created on: 30-Sep-2017
 *      Author: sunbeam
 */


#include<iostream>
using namespace std;

#include<cstring>
#include<stack>

enum menu_option{ EXIT, PUSH, POP, PEEK };

int menu(void)
{

	int choice;

	cout << "<========= dynamic stack ==========>" << endl;
	cout << "0. exit" << endl;
	cout << "1. push element" << endl;
	cout << "2. pop element" << endl;
	cout << "3. peek element" << endl;

	cout << "enter the choice: ";
	cin >> choice;

	return choice;
}

int main(void)
{
	stack<int> s;
	int choice;
	int ele;

	while(1)
	{
		choice = menu();
		switch( choice )
		{
		case EXIT: exit(0);

		case PUSH: //push ele onto the stack
			cout << "enter the ele: ";
			cin >> ele;
			s.push(ele);
			cout << ele << " is pushed sucessfully..." << endl;

			break;

		case POP: //pop ele from the stack
			if( !s.empty())
			{
				cout << "popped ele is: " <<  s.top() << endl;
				s.pop();
			}
			else
				cout << "stack underflow !!!" << endl;

			break;

		case PEEK: //peek the element from stack
			if( !s.empty())
			{
				cout << "topmost ele is: " <<  s.top() << endl;
			}
			else
				cout << "stack underflow !!!" << endl;

			break;
		}
	}

	return 0;
}






