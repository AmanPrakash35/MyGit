#include<iostream>
using namespace std;

#include"../include/Stack.h"

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
	 Stack<int> stack;
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
