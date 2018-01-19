#include<new>
#include<iostream>
using namespace std;

/*int main( void )
{
	int* ptr = new int;
	//int* ptr = ( int* )::operator new(sizeof( int ) );

	*ptr = 125;
	cout<<"Value	:	"<<*ptr<<endl;

	delete ptr;
	//::operator delete(ptr);
	return 0;
}*/

/*class Complex
{
public:
	Complex( void )
	{
		cout<<"Inside ctor"<<endl;
	}
	Complex( int real, int imag )
	{
		cout<<"Inside ctor"<<endl;
	}
};
int main( void )
{
	//Complex* ptr = ( Complex* ) malloc( sizeof( Complex ) );

	//Complex* ptr =  new Complex;

	Complex* ptr1 =  new Complex();

	Complex* ptr2 =  new Complex( 10, 20 );
	return 0;
}*/

/*int main( void )
{
	int* ptr = new int[ 3 ];
	//int* ptr = ( int* )::operator new[]( 3 * sizeof( int ) );
	ptr[ 0 ] = 10;
	ptr[ 1 ] = 20;
	ptr[ 2 ] = 30;
	for( int index = 0; index < 3; ++ index )
		cout<<ptr[ index ] <<endl;
	delete[] ptr;
	//::operator delete[](ptr);
	return 0;
}*/

int main( void )
{
	int count = 100000000000;
	int* ptr = new int[ count ];


	return 0;
}








