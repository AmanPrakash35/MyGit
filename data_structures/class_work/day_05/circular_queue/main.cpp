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
		rear = -1;
		front = -1;

		memset(arr, 0, sizeof(arr));
	}

	bool is_queue_full(void)
	{
		return ( front == (rear + 1) % SIZE );
	}

	bool is_queue_empty(void)
	{
		return ( rear == -1 && front == rear );
	}

	void insert_element(int ele)
	{
		//1. check queue is not full

		//2. increment rear by 1
		rear = ( rear + 1 ) % SIZE;

		//3. insert/push ele into the queue at rear position
		arr[  rear ] = ele;

		//4. if front == -1 then make it as 0
		if( front == -1 )
			front = 0;
	}

	int remove_element(void)
	{
		//1. check queue is not empty

		//2. store the ele at front in temp
		int temp = arr[ front ];

		//3. increment the front by 1(remove element)
		if( front == rear )//we are deleting last ele from cqueue
			front = rear = -1;//reinitilaize cqueue
		else//increment front by 1
			front = ( front + 1 ) % SIZE;

		//4. return the value of deleted ele
		return temp;
	}
};


enum menu_options{ EXIT, INSERT_ELE, DELETE_ELE };

int menu(void)
{
	int choice;
	queue_t q;

	cout << "<========== circular queue ==========> " << endl;
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

/*
circular queue:
1. insert/add/push:
	- check queue is not full
	- increment the rear by 1
 	- insert/push ele into the queue at rear
	position
	- if( front == -1)
		front = 0


	2. remove/delete/pop:
	- check queue is not empty
	- store the ele at front pos in temp
	- delete ele from queue
	if( front == rear )
		front = rear = -1
	else
		increment front by 1

--------------------------------------------------
//increment the front by 1
front = (front + 1) % SIZE

--------------------------------------------------
//increment the rear by 1
rear = (rear + 1) % SIZE

for front = 0 => (0+1)%5 => 1%5=>1
for front = 1 => (1+1)%5 => 2%5=>2
for front = 2 => (2+1)%5 => 3%5=>3
for front = 3 => (3+1)%5 => 4%5=>4
for front = 4 => (4+1)%5 => 5%5=>0


front == (rear+1) % SIZE
for front = 0 & rear = 4
0 == (4+1) % 5 => 0 == 5%5 => 0 == 0

if front = 1 & rear = 0
=> 1 == 0+1 % 5 => 1 == 1 % 5 => 1 == 1

to implement dynamic queue using linked list following operations
can be used:


insert: add_last
remove: delete_first
OR
insert: add_first
remove: delete_last

*/



