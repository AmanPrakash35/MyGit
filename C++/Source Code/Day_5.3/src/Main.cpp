#include<iostream>
#include<string>
using namespace std;
class InvalidListOperationException
{
private:
	const string message;
public:
	InvalidListOperationException( const string& message ) throw( ): message( message )
	{	}
	const string getMessage( void )const throw()
	{
		return this->message;
	}
};
class LinkedList
{
private:
	class Node
	{
	private:
		int data;
		Node* next;
	public:
		Node( int data = 0 )throw( )
		{
			this->data = data;
			this->next = NULL;
		}
		friend class LinkedList;
	};
private:
	Node* head;
	Node* tail;
public:
	LinkedList( void )throw( )
	{
		this->head = NULL;
		this->tail = NULL;
	}
	bool empty( void )const throw( )
	{
		return this->head == NULL;
	}
	/*void addFirst( int data )
	{
		Node* newnode = new Node( data );
		if( this->empty( ) )
		{
			this->tail = newnode;
			this->head = newnode;
		}
		else
		{
			newnode->next = this->head;
			this->head = newnode;
		}
	}*/

	void addFirst( int data )throw( bad_alloc )
	{
		Node* newnode = new Node( data );
		if( this->empty( ) )
			this->tail = newnode;
		else
			newnode->next = this->head;
		this->head = newnode;
	}
	/*void addLast( int data )
	{
		Node* newnode = new Node( data );
		if( this->empty( ) )
		{
			this->head = newnode;
			this->tail = newnode;
		}
		else
		{
			this->tail->next = newnode;
			this->tail = newnode;
		}
	}*/
	void addLast( const int data )throw( bad_alloc )
	{
		Node* newnode = new Node( data );
		if( this->empty( ) )
			this->head = newnode;
		else
			this->tail->next = newnode;
		this->tail = newnode;
	}
	void removeFirst( void )throw( InvalidListOperationException )
	{
		if( this->empty( ))
			throw InvalidListOperationException("Linked List is empty");
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
	void removeLast( void )throw( InvalidListOperationException )
	{
		if( this->empty( ))
			throw InvalidListOperationException("Linked List is empty");
		else if( this->head == this->tail )
		{
			delete this->head;
			this->head = this->tail = NULL;
		}
		else
		{
			Node* trav = this->head;
			while( trav->next != this->tail )
				trav = trav->next;
			this->tail = trav;
			delete this->tail->next;
			this->tail->next = NULL;
		}
	}
	void printList( void )const throw( InvalidListOperationException )
	{
		if( !this->empty( ) )
		{
			Node* trav = this->head;
			while( trav != NULL )
			{
				cout<<trav->data<<"	";
				trav = trav->next;
			}
			cout<<endl;
		}
		else
			throw InvalidListOperationException("List is empty.");
	}
	~LinkedList( void )
	{
		while( !this->empty( ) )
			this->removeFirst();
	}
};
void accept_record( int& data )
{
	cout<<"Enter data	:	";
	cin>>data;
}
int menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Add First"<<endl;
	cout<<"2.Add Last"<<endl;
	cout<<"3.Remove First"<<endl;
	cout<<"4.Remove Last"<<endl;
	cout<<"5.Print List"<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	int choice,data;
	LinkedList list;
	while( ( choice = ::menu_list( ) ) != 0 )
	{
		try
		{
			switch( choice )
			{
			case 1:
				::accept_record(data);
				list.addFirst( data );
				break;
			case 2:
				::accept_record(data);
				list.addLast( data );
				break;
			case 3:
				list.removeFirst( );
				break;
			case 4:
				list.removeLast( );
				break;
			case 5:
				list.printList( );
				break;
			}
		}
		catch(InvalidListOperationException& ex )
		{
			cout<<ex.getMessage()<<endl;
		}
	}
	return 0;
}
