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
		//1. create newnode
		node_t *newnode = new node_t(data);

		//2. if list is empty
		if( this->is_list_empty() )
		{
			//store the addr of newly created node into the head as well tail
			this->head = newnode;
			this->tail = newnode;
			this->cnt++;
		}
		else
		{
			//store the addr of cur last node in prev of newnode
			newnode->prev = this->tail;

			//store the addr of newly created node into the next of cur last node
			this->tail->next = newnode;

			//store the addr of newly created node/added node at last into the tail
			this->tail = newnode;

			//increment the node count
			this->cnt++;
		}
	}

	void add_first(int data)
	{
		//1. create newnode
		node_t *newnode = new node_t(data);

		//2. if list is empty
		if( this->is_list_empty() )
		{
			//store the addr of newly created node into the head as well tail
			this->head = newnode;
			this->tail = newnode;
			this->cnt++;
		}
		else
		{
			//store the addr of cur first node into the next of newly created node
			newnode->next = this->head;

			//store the addr of newly created node into the prev of cur first node
			this->head->prev = newnode;

			//store the addr of newly created node into the head
			this->head = newnode;

			//increment the node count
			this->cnt++;
		}
	}

	void add_at_position(int data, int pos)
	{
		if( pos == 1 )
			this->add_first(data);
		else
		if( pos == this->cnt+1 )
			this->add_last(data);
		else
		{
			//create a newnode
			node_t *newnode = new node_t(data);

			//traverse the list till (pos-1)th node
			int i = 1;
			node_t *trav = this->head;
			while( i < pos-1 )
			{
				i++;
				trav = trav->next;
			}

			//store the addr of cur (pos)th node's addr into the next of newnode
			newnode->next = trav->next;

			//store the addr of cur (pos-1)th node's addr in prev of newnode
			newnode->prev = trav;

			//store the addr of newnode into the prev of cur (pos)th node
			trav->next->prev = newnode;

			//store the addr of newnode into the next of cur (pos-1)th node
			trav->next = newnode;

			//increment the node count
			this->cnt++;
		}
	}

	void delete_first(void)
	{
		//1. check list is not empty
		if( !this->is_list_empty())
		{
			//2. if list contains only one node
			if( this->head->next == NULL )
			{
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
				this->cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//store the addr of first node into the temp
				node_t *temp = this->head;

				//store the addr of cur second node into the head
				this->head = temp->next;

				//make modified first node's prev part as NULL
				this->head->prev = NULL;

				//delete the node
				delete temp;

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
			//2. if list contains only one node
			if( this->head->next == NULL )
			{
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
				this->cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//store the addr of cur second last node into the tail
				this->tail = this->tail->prev;

				//delete the last node
				delete this->tail->next;

				this->tail->next = NULL;
				this->cnt--;
			}
		}
		else
			cout << "list is empty ..." << endl;
	}

	void delete_at_position(int pos)
	{
		if( pos == 1 )
			this->delete_first();
		else
		if( pos == this->cnt )
			this->delete_last();
		else
		{
			//traverse list till (pos-1)th node
			int i = 1;
			node_t *trav = this->head;

			while( i < pos-1 )
			{
				i++;
				trav = trav->next;
			}

			//store the addr of node which is to delete in a temp
			node_t *temp = trav->next;

			//store the addr of cur (pos-1)th node into the prev of cur (pos+1)th node
			temp->next->prev = trav;

			//store the addr of cur (pos+1)th node into the next of cur (pos-1)th node
			trav->next = temp->next;

			//delete the node
			delete temp;
			temp = NULL;

			this->cnt--;

		}
	}

	void display_list(void)
	{

		if( !this->is_list_empty() )
		{
			node_t *trav = this->head;

			cout << "list is forward dir : head -> ";
			while( trav != NULL )
			{
				cout << trav->data << " -> ";
				trav = trav->next;
			}
			cout << " null " << endl;

			trav = this->tail;

			cout << "list is backward dir: tail -> ";
			while( trav != NULL )
			{
				cout << trav->data << " -> ";
				trav = trav->prev;
			}
			cout << " null " << endl;
		}
		else
			cout << "list is empty ..." << endl;
	}


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

};



int main(void)
{

	list_t l1;

	l1.add_last(11);
	l1.add_last(22);
	l1.add_last(33);
	l1.add_last(44);
	l1.add_last(55);


	l1.display_list();

	//l1.delete_first();
	//l1.add_at_position(40, 4);

	//l1.delete_last();

	//l1.add_first(99);
	l1.add_at_position(50, 5);


	l1.display_list();


	return 0;
}














