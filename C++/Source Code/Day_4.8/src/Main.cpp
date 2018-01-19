#include<iostream>
using namespace std;

/*int main( void )
{
	char name[ 30 ];
	cout<<"Enter name	:	";
	cin>>name;
	cout<<"Name	:	"<<name<<endl;

	int* ptr = new ( name ) int( 125 );
	//int* ptr = (int*)::operator new( sizeof( int ), name );

	cout<<"Value	:	"<<*ptr<<endl;
	//delete ptr;	//Not Allowed

	return 0;
}*/

int main( void )
{
	try
	{
		int count = 1000000000000;
		int* ptr = new ( nothrow )int[ count ];
		//int* ptr = ( int* )::operator new( sizeof( int ) * count, nothrow )

		if( ptr == NULL )
			cout<<"NULL"<<endl;
		else
			cout<<ptr<<endl;
	}
	catch(bad_alloc& ex )
	{
		cout<<ex.what()<<endl;
	}
	return 0;
}
