#include<iostream>
using namespace std;

#include"../include/Exception.h"
using namespace nexception;

#include"../include/Math.h"

void accept_record( int& number )
{
	cout<<"Number	:	";
	cin>>number;
}

void print_record( const int& result )
{
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	int num1;
	accept_record(num1);

	int num2;
	accept_record(num2);

	try
	{
		int result = calculate( num1, num2);
		print_record( result );
	}
	catch(Exception& ex)
	{
		ex.printStackTrace();
	}
	catch(...)
	{
		cout<<"Generic Catch block"<<endl;
	}
	return 0;
}
