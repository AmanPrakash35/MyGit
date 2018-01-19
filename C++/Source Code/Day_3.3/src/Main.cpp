#include<iostream>
using namespace std;

/*
void sum( int num1, int num2 )
{
	int result = num1 + num2;
	cout<<"Result	:	"<<result<<endl;
}
void sum( int num1, int num2, int num3 )
{
	int result = num1 + num2+ num3;
	cout<<"Result	:	"<<result<<endl;
}
void sum( int num1, int num2, int num3, int num4 )
{
	int result = num1 + num2+ num3 + num4;
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	sum( 10, 20 );
	sum( 10, 20, 30 );
	sum( 10, 20, 30, 40 );
	return 0;
}
*/
/*int defaultValue = 0;
void sum( int num1, int num2, int num3, int num4 = defaultValue )*/
/*void sum( int num1, int num2, int num3 = 0, int num4 = 0 )
{
	int result = num1 + num2+ num3 + num4;
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	sum( 10, 20 );
	sum( 10, 20, 30 );
	sum( 10, 20, 30, 40 );
	return 0;
}*/

/*class Complex
{
private:
	int real;
	int imag;
public:
	Complex( void )
	{
		this->real = 0;
		this->imag = 0;
	}
	Complex( int value )
	{
		this->real = value;
		this->imag = value;
	}
	Complex( int real, int imag )
	{
		this->real = real;
		this->imag = imag;
	}
	void printRecord( void )
	{
		cout<<"Real	:	"<<this->real<<endl;
		cout<<"Imag	:	"<<this->imag<<endl;
	}
};
int main( void )
{
	Complex c1;
	c1.printRecord();

	Complex c2( 10 );
	c2.printRecord();

	Complex c3(10,20);
	c3.printRecord();
	return 0;
}*/

/*class Complex
{
private:
	int real;
	int imag;
public:
	Complex( int real = 0, int imag = 0 ) : real( real ), imag( imag )
	{	}
	void printRecord( void )
	{
		cout<<"Real	:	"<<this->real<<endl;
		cout<<"Imag	:	"<<this->imag<<endl;
	}
};
int main( void )
{
	Complex c1;
	c1.printRecord();

	Complex c2( 10 );
	c2.printRecord();

	Complex c3(10,20);
	c3.printRecord();
	return 0;
}*/


class Complex
{
private:
	int real;
	int imag;
public:

	Complex( int real = 0, int imag = 0 ) ;

	void printRecord( void )const;

};
Complex::Complex( int real, int imag ) : real( real ), imag( imag )
{	}
void Complex::printRecord( void )const
{
	cout<<"Real	:	"<<this->real<<endl;
	cout<<"Imag	:	"<<this->imag<<endl;
}
int main( void )
{
	Complex c1;
	c1.printRecord();

	Complex c2( 10 );
	c2.printRecord();

	Complex c3(10,20);
	c3.printRecord();
	return 0;
}

