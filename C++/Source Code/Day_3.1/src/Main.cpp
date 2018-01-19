#include<iostream>
using namespace std;

/*int main( void )
{
	int num1 = 10;
	int& num2 = num1;

	cout<<"Num1	:	"<<num1<<"	"<<&num1<<endl;
	cout<<"Num2	:	"<<num2<<"	"<<&num2<<endl;
	return 0;
}*/
/*int main( void )
{
	int num1 = 10;
	int& num2 = num1;

	++ num1;
	++ num2;

	cout<<"Num1	:	"<<num1<<endl;
	cout<<"Num2	:	"<<num2<<endl;
	return 0;
}*/
/*int main( void )
{
	int num1 = 10;
	int& num2 = num1;
	const int& num3 = num1;

	++ num1;
	++ num2;
	//++ num3;	//Not Allowed

	cout<<"Num1	:	"<<num1<<endl;
	cout<<"Num2	:	"<<num2<<endl;
	cout<<"Num3	:	"<<num3<<endl;
	return 0;
}*/
/*int main( void )
{
	int num1 = 10;
	int num2 = 20;
	int& num3 = num1;
	++ num3;
	num3 = num2;

	cout<<"Num1	:	"<<num1<<endl;
	cout<<"Num2	:	"<<num2<<endl;
	cout<<"Num3	:	"<<num3<<endl;
	return 0;
}*/
/*int main( void )
{
	int number = 10;
	int *ptr = &number;
	int **pptr = &ptr;

	cout<<"Num1	:	"<<number<<endl;
	cout<<"ptr	:	"<<ptr<<endl;
	cout<<"pptr	:	"<<pptr<<endl;
	return 0;
}*/
/*int main( void )
{
	int num1 = 10;
	int& num2 = num1;
	int& num3 = num2;

	++ num1;
	++ num2;
	++ num3;
	cout<<"Num1	:	"<<num1<<endl;
	cout<<"Num2	:	"<<num2<<endl;
	cout<<"Num3	:	"<<num3<<endl;
	return 0;
}*/
/*int main( void )
{
	int num1 = 10;
	const int& num2 = num1;
	int& num3 = (int&)num2;

	++ num1;
	++ num2;
	++ num3;

	cout<<"Num1	:	"<<num1<<endl;
	cout<<"Num2	:	"<<num2<<endl;
	cout<<"Num3	:	"<<num3<<endl;
	return 0;
}*/
/*int main( void )
{
	int num1 = 10;

	int& num2 = num1;
	//int* const num2 = &num1;

	cout<<"Num2	:	"<<num2<<endl;
	//cout<<"Num2	:	"<<*num2<<endl;

	return 0;
}*/

/*class Test
{
private:
	char& ch3;
public:
	Test( char ch2 ) : ch3( ch2 )
	{	}
};
int main( void )
{
	char ch1 = 'A';
	Test t( ch1 );
	size_t size = sizeof( t );
	cout<<"Size	:	"<<size<<endl;
	return 0;
}*/


/*int main( void )
{
	int* ptr;
	int& number;


	int* ptr = NULL;
	int& num1 = NULL;
	//int* const num1 = & NULL;


	char* argv[ 3 ];
	char& argv[ 3 ];

	return 0;
}*/

class Test
{	};
void display( void )
{
	cout<<"Inside display"<<endl;
}
int main( void )
{
/*	double num1 = 10;
	double& num2 = num1;*/

	/*int number = 10;
	int* ptr1 = &number;
	int*& ptr2 = ptr1;*/

	/*int arr1[ 3 ] = { 10, 20, 30 };
	int (&arr2)[ 3 ] = arr1;
	for( int index = 0; index < 3; ++ index )
		cout<<arr2[ index ]<<endl;*/

/*	void (*ptr)( void ) = display;
	ptr();*/

/*	void (&print)( void ) = display;
	print();*/

	Test t1;
	Test& t2 = t1;
	return 0;
}









