#include<iostream>
using namespace std;

/*class Test
{
private:
	const int num1;
public:
	Test( void ) : num1( 10 )
	{
		//this->num1 = 10;
	}
	void showRecord( void )
	{
		//this->num1 = 10;
		cout<<"Num1	:	"<<this->num1<<endl;
	}
	void printRecord( void )
	{
		//this->num1 = 10;
		cout<<"Num1	:	"<<this->num1<<endl;
	}
};

int main( void )
{
	Test t;
	t.printRecord();
	return 0;
}*/


/*class Test
{
private:
	int num1;
	int num2;
public:
	Test( void ) : num1( 10 ) , num2( 20 )
	{	}
	//Test* const this;
	void showRecord( void )
	{
		this->num1 = 100;
		cout<<"Num1	:	"<<this->num1<<endl;
		this->num2 = 200;
		cout<<"Num2	:	"<<this->num2<<endl;
	}
	//const Test* const this
	void printRecord( void )const
	{
		Test t;
		t.num1 = 11;
		t.num2 = 22;

		//this->num1 = 500;
		cout<<"Num1	:	"<<this->num1<<endl;
		//this->num1 = 600;
		cout<<"Num2	:	"<<this->num2<<endl;
	}
};

int main( void )
{
	Test t;

	t.showRecord();

	t.printRecord();
	return 0;
}*/


/*class Test
{
private:
	 mutable int count;
public:
	Test( void ) : count( 0 )
	{	}
	void showRecord( void )const
	{
		++ this->count;
		cout<<"Count	:	"<<this->count<<endl;
	}
};
int main( void )
{
	Test t1;
	t1.showRecord();
	t1.showRecord();
	t1.showRecord();

	Test t2;
	t2.showRecord();
	t2.showRecord();



	return 0;
}*/

/*class Test
{
private:
	  int count;
public:
	Test( void ) : count( 10 )
	{	}
	//Test* const this
	void showRecord( void )
	{
		cout<<"Count	:	"<<this->count<<endl;
	}
	//const Test* const this
	void printRecord( void )const
	{
		cout<<"Count	:	"<<this->count<<endl;
	}
};
int main( void )
{
	Test t1;

	const Test t2;
	//t2.showRecord();
	t2.printRecord();

	return 0;
}*/

