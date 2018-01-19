#include<iostream>
using namespace std;
/*void print( int num1 )
{
	cout<<"int	:	"<<num1<<endl;
}
void print( float num2 )
{
	cout<<"float	:	"<<num2<<endl;
}
int main( void )
{
	print( 10 );	//int	:	10
	//print( 10.5 );	//Ambiguity Error
	//print( ( int) 10.5 );	//int	:	10
	print( 10.5f );	//float	:	10.5
	return 0;
}*/
/*void print( int number )
{
	cout<<"int	:	"<<number<<endl;
}
void print( int& number )
{
	cout<<"int&	:	"<<number<<endl;
}
int main( void )
{
	//print( 10 );	//int	:	10

	int number = 10;
	print( number );	//Ambiguity Error
	return 0;
}*/
/*void print( int num1 = 0 )
{
	cout<<"Num1	:	"<<num1<<endl;
}
void print( int num1, int num2 = 0 )
{
	cout<<"Num1	:	"<<num1<<endl;
	cout<<"Num2	:	"<<num2<<endl;
}
int main( void )
{
	//print( );	//Num1	:	0

	//print( 10 );	//Ambiguity Error

	print( 10, 20 );	//Num1	:	10;	Num2	:	20

	return 0;
}*/

/*void print( const char* name )
{
	cout<<"const char*	:	"<<name<<endl;
}
void print( char * const name )
{
	cout<<"char * const	:	"<<name<<endl;
}
int main( void )
{
	//char name[] = "SunBeam";
	//print(name);	//char * const	:	SunBeam

	//const char name[ ] = "SunBeam";
	//print( name );	//const char*	:	SunBeam

	print( "SunBeam" );	//const char*	:	SunBeam
	return 0;
}*/

class Test
{
public:
	//Test* const this
	void print( void )
	{
		cout<<"void print( void )"<<endl;
	}
	//const Test* const this
	void print( void )const
	{
		cout<<"void print( void )const"<<endl;
	}
};
int main( void )
{
	const Test t1;
	t1.print();

	Test t2;
	t2.print();
	return 0;
}
