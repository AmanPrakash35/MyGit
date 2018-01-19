#include<cstring>
#include<iostream>
#include<string>
using namespace std;

class LinkedList;
class Iterator;

class Node
{
private:
	int data;
	Node* next;
public:
	Node( int data = 0 )
	{
		this->data = data;
		this->next = NULL;
	}
	friend class LinkedList;
	friend class Iterator;
};
class Iterator
{
private:
	Node* trav;
public:
	Iterator( Node* trav )throw( )
	{
		this->trav = trav;
	}
	bool operator!=( Iterator& other )const throw( )
	{
		return this->trav != other.trav;
	}
	int operator*( void )
	{
		return this->trav->data;
	}
	void operator++( void )
	{
		this->trav = this->trav->next;
	}
};
class LinkedList
{
private:
	Node* head;
	Node* tail;
public:
	LinkedList( void )throw( )
	{
		this->head = NULL;
		this->tail = NULL;
	}
	LinkedList( const LinkedList& other  )throw( bad_alloc )
	{
		this->head = this->tail = NULL;
		Node* trav = other.head;
		while( trav != NULL )
		{
			this->addLast( trav->data );
			trav = trav->next;
		}
	}
	bool empty( void ) const throw( )
	{
		return this->head == NULL;
	}
	void addLast( const int data )throw( bad_alloc )
	{
		Node* newnode = new Node( data );
		if( this->empty( ))
			this->head = newnode;
		else
			this->tail->next = newnode;
		this->tail = newnode;
	}
	void removeFirst( void )throw( string )
	{
		if( this->empty( ) )
			throw string("List is empty");
		else if( this->head == this->tail )
		{
			delete this->head;
			this->head = this->tail = NULL;
		}
		else
		{
			Node* ptrNode = this->head;
			this->head = this->head->next;
			delete ptrNode;
		}
	}
	Iterator begin( void )
	{
		Iterator itr( this->head );
		return itr;
	}
	Iterator end( void )
	{
		Iterator itr( NULL );
		return itr;
	}
	~LinkedList( void )
	{
		while( !this->empty( ) )
			this->removeFirst();
	}
};
int main( void )
{
	LinkedList list;
	list.addLast(10);
	list.addLast(20);
	list.addLast(30);

	Iterator itrStart = list.begin();
	Iterator itrEnd = list.end();

	while( itrStart != itrEnd ) //itrStart.operator!=( itrEnd )
	{
		cout<< *itrStart<<"	";	//itrStart.operator*()
		++ itrStart;	//itrStart.operator++()
	}

	return 0;
}
