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
		this->real = 0;
		this->imag = 0;
	}
	Complex( int real, int imag )
	{
		this->real = real;
		this->imag = imag;
	}
	//Complex* const this = &c1;
	//Complex& other = c2;
	Complex operator+( Complex& other )
	{
		Complex temp;
		temp.real = this->real + other.real;
		temp.imag = this->imag + other.imag;
		return temp;
	}
	Complex operator+( int value )
	{
		Complex temp;
		temp.real = this->real + value;
		temp.imag = this->imag + value;
		return temp;
	}
	bool operator==( const Complex& other )
	{
		return this->real == other.real && this->imag == other.imag;
	}
	Complex operator+=( Complex& other )
	{
		this->real += other.real;
		this->imag += other.imag;
		return *this;
	}
	//Pre-increment
	Complex operator++( void )
	{
		Complex temp;
		temp.real = ++ this->real;
		temp.imag = ++ this->imag;
		return temp;
	}

	//Post-increment
	Complex operator++( int )
	{
		Complex temp;
		temp.real = this->real ++;
		temp.imag = this->imag ++;
		return temp;
	}
	void printRecord( void )
	{
		cout<<"Real	:	"<<this->real<<endl;
		cout<<"Imag	:	"<<this->imag<<endl;
	}
};

int main( void )
{
	Complex c1(10,20);

	//c3 = c1 + c2;	//	c3 = c1.operator+( c2 );
	//c3 = c1 + 5;	//	c3 = c1.operator+( 5 )
	//c3 = 5 + c1;	//5.operator+( c1 );	//Not Ok
	//cout<< ((c1 == c2 ) ? "Equal":"Not Equal")<<endl;

	//c3 = c1 += c2;	//c1.operator+=(c2);


	Complex c2 = ++ c1;	//Complex c2 = c1.operator++( )

	Complex c3 = c1 ++ ;	//Complex c2 = c1.operator++( 0 )

	c1.printRecord();
	c2.printRecord();
	return 0;
}
