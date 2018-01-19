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

class queue_t
{
private:
	int arr[SIZE];
	int rear;
	int front;
public:
	queue_t(void)
	{
		this->rear = -1;
		this->front = -1;

		/*
		for( int i = 0 ; i < SIZE ; i++ )
			this->arr[ i ] = 0;
		*/
		memset(this->arr, 0, sizeof(this->arr));
	}

	bool is_queue_full(void)
	{
		return ( this->rear == SIZE-1 );
	}

	bool is_queue_empty(void)
	{
		return ( this->rear == -1 || this->front > this->rear );
	}

	void insert_element(int ele)
	{
		//1. check queue is not full

		//2. increment rear by 1
		this->rear++;

		//3. insert/push ele into the queue at rear position
		this->arr[ this->rear ] = ele;

		//4. if front == -1 then make it as 0
		if( this->front == -1 )
			this->front = 0;
	}

	int remove_element(void)
	{
		//1. check queue is not empty

		//2. store the ele at front in temp
		int temp = this->arr[ this->front ];

		//3. increment the front by 1(remove element)
		this->front++;

		//4. return the value of deleted ele
		return temp;
	}
};


enum menu_options{ EXIT, INSERT_ELE, DELETE_ELE };

int menu(void)
{
	int choice;
	queue_t q;

	cout << "<========== linear queue ==========> " << endl;
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
	queue_t q;

	while(1)
	{
		choice = menu();
		switch( choice )
		{
		case EXIT: exit(0);

		case INSERT_ELE: //insert element into the queue
			if( !q.is_queue_full() )
			{
				int ele;
				cout << "enter the element: ";
				cin >> ele;
				q.insert_element(ele);
				cout << ele << " inserted into the queue successfully..." << endl;
			}
			else
				cout << " queue overflow !!!" << endl;

			break;

		case DELETE_ELE: //delete element into the queue
			if( !q.is_queue_empty())
			{
				cout << "deleted ele is: " << q.remove_element() << endl;
			}
			else
				cout << " queue underflow !!!" << endl;

			break;

		}//end of switch control block
	}
	return 0;
}


