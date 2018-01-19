#include<iostream>
using namespace std;

/*class Test
{
private:
	int num1;
	int num2;
	int num3;
	int num4;
public:
	Test( void ) : num1( 10 ), num2( 20) , num3(30), num4(40)
	{	}
	Test( int num1, int num2, int num3, int num4 ) : num1( num1 ), num2( num2 ) , num3( num3 ), num4( num4 )
	{	}
	void printRecord( void )
	{
		cout<<"Num1	:	"<<this->num1<<endl;
		cout<<"Num2	:	"<<this->num2<<endl;
		cout<<"Num3	:	"<<this->num3<<endl;
		cout<<"Num4	:	"<<this->num4<<endl;
	}
};
int main( void )
{
	Test t1(100,200,300,400);

	t1.printRecord();
	return 0;
}*/


class Test
{
private:
	int num1;
	int num2;
	int num3;
	int num4;
public:
	Test( void );

	Test( int num1, int num2, int num3, int num4 ) ;

	void printRecord( void );
};

Test::Test( void ) : num1( 10 ), num2( 20) , num3(30), num4( 40 )
{	}
Test::Test( int num1, int num2, int num3, int num4 ) : num1( num1 ), num2( num2 ) , num3( num3 ), num4( num4 )
{	}
void Test::printRecord( void )
{
	cout<<"Num1	:	"<<this->num1<<endl;
	cout<<"Num2	:	"<<this->num2<<endl;
	cout<<"Num3	:	"<<this->num3<<endl;
	cout<<"Num4	:	"<<this->num4<<endl;
}
int main( void )
{
	Test t1(100,200,300,400);

	t1.printRecord();
	return 0;
}
