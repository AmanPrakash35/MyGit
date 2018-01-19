#include<iostream>
using namespace std;

/*void print( void )
{
	int count = 0;
	++ count;
	cout<<"Count	:	"<<count<<endl;
}
int main( void )
{
	::print();	//1
	::print();	//1
	::print();	//1
	return 0;
}*/

/*
void print( void )
{
	static int count = 0;
	++ count;
	cout<<"Count	:	"<<count<<endl;
}
int main( void )
{
	::print();	//1
	::print();	//2
	::print();	//3
	return 0;
}*/

/*class Test
{
private:
	int num1;			//Instance Variable
	int num2;			//Instance Variable
	static const int num3;	// Class level variable
public:
	Test( void )
	{
		this->num1 = 0;
		this->num2 = 0;
	}
	Test( int num1, int num2 )
	{
		this->num1 = num1;
		this->num2 = num2;
	}
	void print( void )
	{
		cout<<"Num1	:	"<<this->num1<<endl;
		cout<<"Num2	:	"<<this->num2<<endl;
		cout<<"Num3	:	"<<Test::num3<<endl;
	}
};
const int Test::num3 = 500;	//Global definition : to get space for num3
int main( void )
{
	Test t1(10,20);
	t1.print();

	Test t2(30,40);
	t2.print();

	Test t3(50,60);
	t3.print();
	return 0;
}*/


/*class Test
{
private:
	int num1;			//Instance Variable
	int num2;			//Instance Variable
	static int num3;	// Class level variable
public:
	Test( void )
	{
		this->num1 = 0;
		this->num2 = 0;
	}
	int getNum1( void )
	{
		return this->num1;
	}
	void setNum1( int num1 )
	{
		this->num1 = num1;
	}
	int getNum2( void )
	{
		return this->num2;
	}
	void setNum2( int num2 )
	{
		this->num2 = num2;
	}
	static int getNum3( void )
	{
		return Test::num3;
	}
	static void setNum3( int num3 )
	{
		Test::num3 = num3;
	}
	static void invoke()
	{
		Test t1;
		t1.setNum1(10);
		t1.setNum2(20);
		Test::setNum3(30);
	}
};
int Test::num3;	//Global definition : to get space for num3
void accept_record( Test& t1 )
{
	int num1;
	cout<<"Num1	:	";
	cin>>num1;
	t1.setNum1( num1 );

	int num2;
	cout<<"Num2	:	";
	cin>>num2;
	t1.setNum2(num2);

	int num3;
	cout<<"Num3	:	";
	cin>>num3;
	Test::setNum3(num3);
}
void print_record( Test& t1 )
{
	int num1 = t1.getNum1();
	cout<<"Num1	:	"<<num1<<endl;

	int num2 = t1.getNum2();
	cout<<"Num2	:	"<<num2<<endl;

	int num3 = Test::getNum3();
	cout<<"Num3	:	"<<num3<<endl;

}
int main( void )
{
	Test t1;
	accept_record(t1);
	print_record(t1);
	return 0;
}*/

/*class A
{
public:
	static void f1( void )
	{
		cout<<"A.f1"<<endl;
	}
};
class B
{
public:
	static void f2( void )
	{
		cout<<"B.f2"<<endl;
	}
	static void f3( void )
	{
		f1();
		A::f1();

		f2();
		B::f2();
	}
};
int main( void )
{
	B::f3();
	return 0;
}*/

/*class
{
public:
	void showRecord( void )
	{
		cout<<"Inside showRecord"<<endl;
	}
	static void displayRecord( void )
	{
		cout<<"Inside displayRecord"<<endl;
	}
}obj;

int main( void )
{
	obj.showRecord();

	obj.displayRecord();
	return 0;
}*/


/*
class InstanceCounter
{
private:
	static int count;
public:
	InstanceCounter( void )
	{
		++ InstanceCounter::count;
	}
	static int getCount( void )
	{
		return InstanceCounter::count;
	}
};
int InstanceCounter::count;
int main( void )
{
	InstanceCounter c1,c2,c3;
	cout<<"Count	:	"<<InstanceCounter::getCount()<<endl;
	return 0;
}*/

class Singleton
{
private:
	int number;
private:
	Singleton( void ) : number( 0 )
	{
		cout<<"Inside constructor"<<endl;
	}
	Singleton( const Singleton& other ) : number( other.number )
	{
		cout<<"Inside copy constructor"<<endl;
	}
public:

	int getNumber( void )
	{
		return this->number;
	}
	void setNumber( int number )
	{
		this->number = number;
	}
	static Singleton& getInstance( void )
	{
		static Singleton s1;
		return s1;
	}
};
int main( void )
{
	Singleton& s1 = Singleton::getInstance();
	s1.setNumber(10);
	cout<<"Number	:	"<<s1.getNumber()<<endl;
	return 0;
}
