/*
 * main.cpp
 *
 *  Created on: 29-Sep-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;

#include<cstring>

#define SIZE 5

class stack_t
{
private:
	int arr[SIZE];
	int top;
public:
	stack_t(void)
	{
		memset(this->arr,0,sizeof(this->arr));
		this->top = -1;
	}

	bool is_stack_full(void)
	{
		return ( this->top == SIZE-1 );
	}

	bool is_stack_empty(void)
	{
		return ( this->top == -1 );
	}

	void push_element(int ele)
	{
		/*
		//2. increment the top by 1
		this->top++;

		//3. push ele onto the stack at top position
		this->arr[ this->top ] = ele;
		*/
		this->arr[ ++this->top ] = ele;
	}


	int pop_element(void)
	{
		/*
		//2. store the topmost ele in temp
		int temp = this->arr[ this->top ];

		//3. decrement the top by 1(pop ele)
		this->top--;

		//4. return the popped ele
		return temp;
		*/
		return ( this->arr[ this->top-- ]);
	}

	int peek_element(void)
	{
		//return the topmost ele
		return ( this->arr[ this->top ]);
	}

};

enum menu_option{ EXIT, PUSH, POP, PEEK };

int menu(void)
{
	int choice;

	cout << "<========= static stack ==========>" << endl;
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
	stack_t s;
	int choice;
	int ele;

	while(1)
	{
		choice = menu();
		switch( choice )
		{
		case EXIT: exit(0);

		case PUSH: //push ele onto the stack
			if( !s.is_stack_full() )
			{
				cout << "enter the ele: ";
				cin >> ele;
				s.push_element(ele);
				cout << ele << " is pushed sucessfully..." << endl;
			}
			else
				cout << "stack overflow !!!" << endl;

			break;

		case POP: //pop ele from the stack
			if( !s.is_stack_empty())
			{
				cout << "popped ele is: " << s.pop_element() << endl;
			}
			else
				cout << "stack underflow !!!" << endl;

			break;

		case PEEK: //peek the element from stack
			if( !s.is_stack_empty())
			{
				cout << "topmost ele is: " << s.peek_element() << endl;
			}
			else
				cout << "stack underflow !!!" << endl;

			break;
		}
	}

	return 0;
}



