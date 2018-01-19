/*
 * main.cpp
 *
 *  Created on: 28-Sep-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

class list_t;

class node_t
{
private:
	int data;
	node_t *next;
public:
	node_t(int data)
	{
		this->data = data;
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

	void add_at_last(int data)
	{
		//1. create a newnode
		node_t *newnode = new node_t(data);

		//2. if list is empty
		if( this->is_list_empty() )
		{
			//attach newly created node to head as well tail
			newnode->next = newnode;
			this->head = newnode;
			this->tail = newnode;
			this->cnt++;
		}
		else//if list is not empty
		{
			newnode->next = this->head;
			this->tail->next = newnode;
			this->tail = newnode;
			//increment the count for nodes in the list
			this->cnt++;
		}
	}

	void add_at_first(int data)
	{
		//1. create a newnode
		node_t *newnode = new node_t(data);

		//2. if list is empty
		if( this->is_list_empty() )
		{
			//attach newly created node to head as well tail
			newnode->next = newnode;
			this->head = newnode;
			this->tail = newnode;
			this->cnt++;
		}
		else//if list is not empty
		{
			//store the addr of cur first node into the next of newnode
			newnode->next = this->head;

			//store the addr of newly created  node into the head
			this->head = newnode;

			//store the addr of (newly added first node) newly created node into the next of last node
			this->tail->next = this->head;
			this->cnt++;
		}
	}

	void display_list(void)
	{
		if( !this->is_list_empty())
		{
			node_t *trav = this->head;

			cout << "list is : head -> ";
			do
			{
				cout << trav->data << " -> ";
				trav = trav->next;

			}while(trav != this->head );

			cout << " head " << endl;
		}
		else
			cout << "list is empty..." << endl;
	}

	void delete_first(void)
	{
		//1. check list is not empty
		if( !this->is_list_empty())
		{
			//2. if list contains only one node
			if( this->head == this->head->next )
			{
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
				this->cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//strore the addr of first node into temp
				node_t *temp = this->head;

				//store the addr of cur second node into the head
				this->head = temp->next;

				//store the addr of modified first node into the next of last node
				this->tail->next = this->head;

				//delete the node
				delete temp;
				temp = NULL;

				//decrement the node count
				this->cnt--;
			}

		}
		else
			cout << "list is empty ...." << endl;
	}

	void delete_last(void)
	{
		//1. check list is not empty
		if( !this->is_list_empty())
		{
			//2. if list contains only one node
			if( this->head == this->head->next )
			{
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
				this->cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//traverse the list till second last node
				node_t *trav = this->head;
				while( trav->next != this->tail )
					trav = trav->next;

				//delete the last node
				delete trav->next;

				//store the addr of modified last node into the tail
				this->tail = trav;

				//store the addr of first node into the last node
				this->tail->next = this->head;

				//decrement the node count
				this->cnt--;
			}

		}
		else
			cout << "list is empty ...." << endl;
	}

	~list_t(void)
	{
		if( !this->is_list_empty())
			free_list();
		else
			cout << "list is empty ..." << endl;
	}

	void free_list(void)
	{
		while( !this->is_list_empty() )
			this->delete_last();

		cout << "all heap memory freed sucessfully...." << endl;
	}

};


int main(void)
{

	list_t l1;

	l1.add_at_last(10);

	l1.add_at_last(20);
	l1.add_at_last(30);
	l1.add_at_last(40);
	l1.add_at_last(50);


	l1.display_list();

	l1.delete_last();

	l1.display_list();


	return 0;
}




