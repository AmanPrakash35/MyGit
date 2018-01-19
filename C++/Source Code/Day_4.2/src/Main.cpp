#include<cstring>
#include<iostream>
#include<string>
using namespace std;

class Exception
{
private:
	string message;
public:
	Exception( const string message = "" ) : message( message )
	{	}
	string getMessage() const
	{
		return this->message;
	}
};
#define SIZE	5
class Stack
{
private:
	int top;
	int arr[ SIZE ];
public:
	Stack( void ) throw( ) : top( - 1 )
	{
		memset(this->arr, 0, sizeof( int ) * SIZE );
	}
	bool empty( void )const throw( )
	{
		return this->top == -1;
	}
	bool full( void )const throw( )
	{
		return this->top == SIZE - 1;
	}
	void push( const int data )throw( Exception )
	{
		if( this->full( ) )
			throw Exception("Stack is full");
		this->arr[ ++ this->top ] = data;
	}
	int peek( void )const throw( Exception )
	{
		if( this->empty() )
			throw Exception("Stack is empty");
		return this->arr[ this->top ];
	}
	void pop( void )throw( Exception )
	{
		if( this->empty() )
			throw Exception("Stack is empty");
		-- this->top;
	}
};
void accept_record( int& data )
{
	cout<<"Enter data	:	";
	cin>>data;
}
void print_record(const int& data )
{
	cout<<"Popped element is	:	"<<data<<endl;
}
int menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Push"<<endl;
	cout<<"2.Pop"<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	 int choice, data;
	 Stack stack;
	 while ( ( choice = menu_list( ) ) != 0 )
	 {
		 try
		 {
			 switch( choice )
			 {
			 case 1:
				 ::accept_record(data);
				 stack.push( data );
				 break;
			 case 2:
				 data = stack.peek();
				 print_record(data);
				 stack.pop();
				 break;
			 }
		 }
		 catch( Exception& ex)
		 {
			cout<<ex.getMessage()<<endl;
		 }
	 }
	return 0;
}
