#include<iostream>
using namespace std;
/*void swap_object( int x, int y )
{
	int temp = x;
	x = y;
	y = temp;
}
int main( void )
{
	int a = 10;
	int b = 20;

	swap_object( a, b );

	cout<<"a	:	"<<a<<endl;
	cout<<"b	:	"<<b<<endl;
}*/

/*void swap_object( int *x, int *y )
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main( void )
{
	int a = 10;
	int b = 20;

	swap_object( &a, &b );

	cout<<"a	:	"<<a<<endl;
	cout<<"b	:	"<<b<<endl;
}*/

/*//void swap_object( int* const x, int* const y )
void swap_object( int& x, int& y )
{
	int temp = x;	//int temp = *x;
	x = y;			//*x = *y;
	y = temp;		//*y = temp;
}
int main( void )
{
	int a = 10;
	int b = 20;

	swap_object( a, b );

	cout<<"a	:	"<<a<<endl;
	cout<<"b	:	"<<b<<endl;
}*/



/*void swap_object( int x, int y )
{
	int temp = x;
	x = y;
	y = temp;
}
void swap_object( int& x, int& y )
{
	int temp = x;
	x = y;
	y = temp;
}
int main( void )
{
	int a = 10;
	int b = 20;

	//swap_object( 10, 20 );
	swap_object( a, b );	//Error

	cout<<"a	:	"<<a<<endl;
	cout<<"b	:	"<<b<<endl;
}*/

/*int getValue( void )
{
	int number = 10;
	return number;
}
int main( void )
{
	int num1 = getValue();
	cout<<"Num1	:	"<<num1<<endl;
	return 0;
}*/

/*int* getValue( void )
{
	static int number = 10;
	return &number;
}
int main( void )
{
	int* ptr = getValue();
	cout<<"Num1	:	"<<*ptr<<endl;
	return 0;
}*/
/*int& getValue( void )
{
	static int num1 = 10;
	return num1;
}
int main( void )
{
	int& num2 = getValue();
	cout<<"Num1	:	"<<num2<<endl;
	return 0;
}*/

void accept_record( int& number )
{
	cout<<"Enter number	:	";
	cin>>number;
}
void print_record( const int& number )
{
	cout<<"Number	:	"<<number<<endl;
}
int main( void )
{
	int num1;
	accept_record( num1 );
	print_record( num1 );
	return 0;
}
