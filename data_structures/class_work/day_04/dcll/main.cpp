			/*
 * main.cpp
 *
 *  Created on: 28-Sep-2017
 *      Author: sunbeam
 */

/*
 * main.cpp
 *
 *  Created on: 28-Sep-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;

class list_t;

class node_t
{
private:
	node_t *prev;
	int data;
	node_t *next;
public:
	node_t(int data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}

	friend class list_t;
};


class list_t
{
private:
	node_t *head;
	node_t *tail;
	int cnt;

public:

	list_t(void)
	{
		this->head = NULL;
		this->tail = NULL;
		this->cnt = 0;
	}

	bool is_list_empty(void)
	{
		return (this->head == NULL );
	}

	void add_last(int data)
	{
		//1. create a newnode
		node_t *newnode = new node_t(data);

		//2. if list is empty
		if( this->is_list_empty() )
		{
			//attach newly created node to head as well as tail
			this->head = newnode;
			this->tail = newnode;

			newnode->prev = this->tail;
			newnode->next = this->head;
			this->cnt++;
		}
		else
		{
			//store the addr of first node in next of newnode
			newnode->next = this->head;

			//store the addr of cur last node into prev of newnode
			newnode->prev = this->tail;

			//store the addr of newnode into the next of cur last node
			this->tail->next = newnode;

			//modify the value of tail
			this->tail = newnode;

			//store the addr of modified last node into the prev of first node
			this->head->prev = this->tail;
			this->cnt++;
		}
	}

	void add_first(int data)
	{
		//1. create a newnode
		node_t *newnode = new node_t(data);

		//2. if list is empty
		if( this->is_list_empty() )
		{
			//attach newly created node to head as well as tail
			this->head = newnode;
			this->tail = newnode;

			newnode->prev = this->tail;
			newnode->next = this->head;
			this->cnt++;
		}
		else
		{
			newnode->next = this->head;
			newnode->prev = this->tail;

			this->head->prev = newnode;
			this->head = newnode;

			this->tail->next = this->head;
			this->cnt++;
		}
	}


	void delete_first(void)
	{
		//1. check list is not empty
		if( !this->is_list_empty())
		{
			//2. if list contains only node
			if( this->head->next == this->head )
			{
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
				this->cnt = 0;
			}
			else//list contains more than one node
			{
				//store the addr of cur first node into temp
				node_t *temp = this->head;

				this->head = temp->next;

				//store the addr of last node into newly added node
				this->head->prev = this->tail;

				//store the addr of newly added first node into the last node
				this->tail->next = this->head;
				this->cnt--;
			}
		}
		else
			cout << "list is empty ..." << endl;
	}

	void delete_last(void)
	{
		//1. check list is not empty
		if( !this->is_list_empty())
		{
			//2. if list contains only node
			if( this->head->next == this->head )
			{
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
				this->cnt = 0;
			}
			else//list contains more than one node
			{
				this->tail = this->tail->prev;

				delete this->tail->next;

				this->tail->next = this->head;
				this->head->prev = this->tail;
				this->cnt--;
			}
		}
		else
			cout << "list is empty ..." << endl;
	}

	void display_list(void)
	{

		if( !this->is_list_empty() )
		{
			cout << "list in forward dir is : ";
			node_t *trav = this->head;
			do
			{
				cout << trav->data << " ";
				trav = trav->next;
			}while( trav != this->head );
			cout << endl;

			cout << "list in backward dir is: ";

			trav = this->tail;
			do
			{
				cout << trav->data << " ";
				trav = trav->prev;
			}while( trav != this->tail );
			cout << endl;

		}
		else
			cout << "list is empty ..." << endl;
	}


	/*
	void free_list(void)
	{
		while( !this->is_list_empty() )
			//this->delete_first();
			this->delete_last();

		cout << "all heap memory freed successfully...." << endl;
	}


	~list_t()
	{
		if( !this->is_list_empty() )
			this->free_list();
		else
			cout << "list is empty ...." << endl;
	}

	*/
};



int main(void)
{

	list_t l1;

	//l1.add_last(11);
	/*
	l1.add_last(22);
	l1.add_last(33);
	l1.add_last(44);
	l1.add_last(55);
	*/

	l1.display_list();

	//l1.delete_first();
	//l1.add_at_position(40, 4);

	l1.delete_last();

	//l1.add_first(99);


	l1.display_list();


	return 0;
}

















