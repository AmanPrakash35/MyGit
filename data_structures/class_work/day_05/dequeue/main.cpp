/*
 * main.cpp
 *
 *  Created on: 29-Sep-2017
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;

#include<iomanip>
#include<deque>

int main(void)
{
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);


	dq.push_front(5);

	cout << "dequeue ele's are: ";
	deque<int>::iterator itr;
	for( itr = dq.begin() ; itr != dq.end() ; itr++ )
	{
		cout << setw(4) << *itr;
	}
	cout << endl;

	dq.pop_front();
	cout << "dequeue ele's are: ";

	for( itr = dq.begin() ; itr != dq.end() ; itr++ )
	{
		cout << setw(4) << *itr;
	}
	cout << endl;


	return 0;
}



