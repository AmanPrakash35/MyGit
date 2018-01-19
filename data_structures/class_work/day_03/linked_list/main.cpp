/*
 * main.cpp
 *
 *  Created on: 26-Sep-2017
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;

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
	node_t * head;
	int cnt;
public:
	list_t()
	{
		this->head = NULL;
		this->cnt = 0;
	}

	bool is_list_empty(void)
	{
		return (this->head == NULL );
	}

	int get_node_count(void)
	{
		/*
		int cnt = 0;
		node_t *trav = this->head;
		while( trav != NULL )
		{
			cnt++;
			trav = trav->next;
		}
		*/
		return this->cnt;
	}

	void add_at_first(int data)
	{
		//1. create a newnode: allocate memory dynamically for node
		node_t *newnode = new node_t(data);

		//2. if list is empty then newly created will be first node
		if( this->is_list_empty())
		{
			//attach newly created node to head
			this->head = newnode;
			this->cnt++;
		}
		else //3. if list is not empty
		{
			//store the addr of cur first node into the next of newnode
			newnode->next = this->head;

			//store the addr of newly created into the head
			this->head = newnode;
			this->cnt++;
		}
	}

	void add_at_last(int data)
	{
		//1. create a newnode: allocate memory dynamically for node
		node_t *newnode = new node_t(data);

		//2. if list is empty then newly created will be first node
		if( this->is_list_empty())
		{
			//attach newly created node to head
			this->head = newnode;
			this->cnt++;
		}
		else //3. if list is not empty
		{
			node_t *trav = this->head;

			//4. traverse the list till last node
			while( trav->next != NULL )
			{
				trav = trav->next;
			}
			//5. attach newly created node to last node
			trav->next = newnode;
			this->cnt++;
		}
	}

	void add_node_at_specific_position(int data, int pos)
	{
		if( pos == 1 )
			this->add_at_first(data);
		else
		if( pos == this->cnt + 1 )
			this->add_at_last(data);
		else//if position in between position
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

			//store the addr of cur (pos)th node into the next of newnode
			newnode->next = trav->next;

			//store the addr of newly created node into next of (pos-1)th node
			trav->next = newnode;
			this->cnt++;

		}
	}

	void delete_first(void)
	{
		//1. if list is not empty
		if( !this->is_list_empty())
		{
			//2. if list contains only one node
			if( this->head->next == NULL )
			{
				delete this->head;
				this->head = NULL;
				this->cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//store the addr of cur first node into the temp
				node_t *temp = this->head;

				//store the addr of cur second node into the head
				this->head = temp->next;

				//delete the first node
				delete temp;
				temp = NULL;
				this->cnt--;
			}
		}
		else
			cout << "list is empty" << endl;
	}

	void delete_last(void)
	{
		//1. if list is not empty
		if( !this->is_list_empty())
		{
			//2. if list contains only one node
			if( this->head->next == NULL )
			{
				delete this->head;
				this->head = NULL;
				this->cnt = 0;
			}
			else//if list contains more than one nodes
			{
				//traverse list till second last node
				node_t *trav = this->head;

				while(trav->next->next != NULL )
					trav = trav->next;

				//delete the last node
				delete trav->next;

				//make second last node's next as NULL
				trav->next = NULL;

				this->cnt--;
			}
		}
		else
			cout << "list is empty" << endl;
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
			int i = 1;
			node_t *trav = this->head;

			//traverse the list till (pos-1)th node
			while( i < pos-1 )
			{
				i++;
				trav = trav->next;
			}

			//store the addr of node to be deleted in a temp
			node_t *temp = trav->next;

			//store the addr of cur (pos+1)th node into next of cur (pos-1)th node
			trav->next = temp->next;

			//delete the node
			delete temp;
			temp = NULL;

			this->cnt--;
		}
	}

	void display_list(void)
	{
		if( !this->is_list_empty())
		{
			cout << "list is : head -> ";
			for( node_t *trav = this->head ; trav != NULL ; trav = trav->next )
			{
				cout << trav->data << " -> ";
			}
			cout << " null " << endl;
		}
		else
			cout << "list is empty" << endl;
	}

	void display_reverse(node_t *trav)
	{
		if( trav == NULL )
			return;
		else
		{
			display_reverse(trav->next);
			cout << trav->data << " ";
		}
	}

	void display_reverse()
	{
		if( !this->is_list_empty())
		{
			cout << "list in reverse order is: ";
			this->display_reverse(this->head);
			cout << endl;
		}
		else
			cout << "list is empty" << endl;
	}

	void reverse_list(void)
	{
		node_t *t1 = this->head;
		node_t *t2 = t1->next;
		node_t *t3 = NULL;

		t1->next = NULL;

		while( t2 != NULL )
		{
			t3 = t2->next;
			t2->next = t1;

			t1 = t2;
			t2 = t3;
		}

		this->head = t1;
	}

	~list_t()
	{
		if( !this->is_list_empty())
			this->free_list();
		else
			cout << "list is empty" << endl;
	}

	void free_list(void)
	{
		while( !this->is_list_empty())
			//this->delete_first();
			this->delete_last();

		cout << "all heap memory freed successfully...." << endl;
	}
};

enum menu_options { EXIT, ADD_LAST, ADD_FIRST, ADD_AT_POSITION, DEL_FIRST,
	DEL_LAST, DEL_POSITON, DISPALY, DISPLAY_REVERSE, REVERSE_LIST };


int menu(void)
{
	int ch;

	cout << "<========= SLLL ==========>" << endl;
	cout << "0. exit" << endl;
	cout << "1. add node into the list at last position" << endl;
	cout << "2. add node into the list at first position" << endl;
	cout << "3. add node into the list at specific position" << endl;
	cout << "4. delete node from the list at first position" << endl;
	cout << "5. delete node into the list at last position" << endl;
	cout << "6. delete node from the list at specific position" << endl;
	cout << "7. display the list" << endl;
	cout << "8. display the list in reverse order" << endl;
	cout << "9. reverse the list" << endl;

	cout << "enter the choice: ";
	cin >> ch;

	return ch;
}

int main(void)
{

	list_t l1;
	int ch;
	int data;
	int pos;

	while(1)
	{
		ch = menu();

		switch( ch )
		{
		case EXIT:
			l1.free_list();
			exit(0);

		case ADD_LAST: //add node into the list at last position
			cout << "enter the data: ";
			cin >> data;

			l1.add_at_last(data);

			break;

		case ADD_FIRST: //add node into the list ar first position
			cout << "enter the data: ";
			cin >> data;

			l1.add_at_first(data);

			break;

		case ADD_AT_POSITION: //add node at specific position
			while(1)
			{
				cout << "enter the position: ";
				cin >> pos;

				if( pos > 0 && pos <= l1.get_node_count()+1 )
					break;
				else
					cout << "invalid position";
			}

			cout << "enter the data: ";
			cin >> data;
			l1.add_node_at_specific_position(data, pos);
			break;

		case DEL_FIRST: //delete node at first position
			l1.delete_first();
			break;

		case DEL_LAST:
			l1.delete_last();
			break;

		case DEL_POSITON:
			while(1)
			{
				cout << "enter the position: ";
				cin >> pos;

				if( pos > 0 && pos < l1.get_node_count() )
					break;
				else
					cout << "invalid position";
			}

			l1.delete_at_position(pos);

			break;

		case DISPLAY_REVERSE:

			l1.display_reverse();

			break;


		case DISPALY: //display the list
			l1.display_list();
			break;

		case REVERSE_LIST:
			l1.reverse_list();
			break;
		}
	}

	return 0;
}


