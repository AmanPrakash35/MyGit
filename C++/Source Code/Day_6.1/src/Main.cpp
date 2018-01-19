#include<cstring>
#include<iostream>
using namespace std;
class Complex
{
private:
	int real;
	int imag;
public:
	Complex( void )
	{
		cout<<"Complex( void )"<<endl;
		this->real = 0;
		this->imag = 0;
	}
	Complex( int real, int imag )
	{
		cout<<"Complex( int,int )"<<endl;
		this->real = real;
		this->imag = imag;
	}
	//Complex* const this = &c2;
	//Complex& other = c1
	Complex( const Complex& other )//Copy ctor
	{
		cout<<"Complex( const Complex& other )"<<endl;
		this->real = other.real;
		this->imag = other.imag;
	}

	/*Complex( const Complex& other ) : real( other.real ), imag( other.imag )
	{	}*/

	/*Complex( const Complex& other )
	{
		memcpy(this, &other, sizeof( Complex));
	}*/
	Complex sum( Complex other )
	{
		Complex temp;
		temp.real =  this->real + other.real;
		temp.imag =  this->imag + other.imag;
		return temp;
	}
	void printRecord( void )
	{
		cout<<"Real	:	"<<this->real<<endl;
		cout<<"Imag	:	"<<this->imag<<endl;
	}
};
/*void swap( void* ptr1, void* ptr2, size_t size )
{
	void* temp = malloc( size );
	memcpy(temp, ptr1, size);
	memcpy(ptr1, ptr2, size);
	memcpy(ptr2, temp, size);
	free( temp );
}*/
int main( void )
{
/*	Complex c1(10,20);	//c1--> parameterized ctor
	Complex c2(30,40);	//c2--> parameterized ctor
	Complex c3;			//c3--> parameterless ctor

	c3 = c1.sum(c2);

	c3.printRecord();*/


/*
	Complex c1;			//c1 -- parameterless ctor
	Complex* ptr = &c1;	// ptr --> ctor will not call
*/

	/*Complex c1(10,20);	//c1--parameterized ctor
	Complex& c2 = c1;	*/

/*
	Complex c1( 10,20);
	Complex c2;
	c2 = c1;	//c2.operator=( c1 )
*/

	/*Complex c1(10,20);
	Complex c2 = c1;*/

	Complex c1( 10,20 );
	Complex c2( c1 );

	return 0;
}
