/*
 * main.cpp
 *
 *  Created on: 29-Sep-2017
 *      Author: sunbeam
 */


#include<iostream>
using namespace std;
#include<iomanip>
#include<list>
#include<string>


class customer
{
private:
	string name;
	string address;
	string contact_number;
public:
	customer( string name = " ", string address = " ", string contact_number = " ")
	{
		this->name = name;
		this->address = address;
		this->contact_number = contact_number;
	}

	//getter function: inspectors

	//setter functions: mutators

	//facilitators

	friend ostream& operator<<( ostream& out, customer& other )
	{
		out << setw(15) << left << other.name;
		out << setw(15) << left << other.address;
		out << setw(15) << left << other.contact_number;

		return out;
	}

};

int main(void)
{
	list<customer> cust_list;

	cust_list.push_back(customer("sachin","pune","9764658120"));
	cust_list.push_back(customer("nilesh","mumbai","9881098108"));
	cust_list.push_back(customer("sandeep","delhi","1234567891"));
	cust_list.push_back(customer("vishal","nashik","97646541536"));

	list<customer>::iterator itr;

	cout << "list of customers are:" << endl;

	for( itr = cust_list.begin() ; itr != cust_list.end() ; itr++ )
	{
		cout << *itr << endl;
	}

	cout << endl;


	return 0;
}

/*
int main(void)
{
	list<int> l1;


	l1.push_back(10);
	l1.push_back(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);

	l1.push_front(5);

	list<int>::iterator itr;

	cout << "list l1 is: ";
	for( itr = l1.begin() ; itr != l1.end() ; itr++ )
	{
		cout << setw(4) << *itr;
	}
	cout << endl;

	l1.pop_front();
	cout << "list l1 is: ";
	for( itr = l1.begin() ; itr != l1.end() ; itr++ )
	{
		cout << setw(4) << *itr;
	}
	cout << endl;

	return 0;
}
*/



