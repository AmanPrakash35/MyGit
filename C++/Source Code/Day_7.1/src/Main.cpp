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
	Complex( const int real, const int imag )
	{
		this->real = real;
		this->imag = imag;
	}
	Complex( const Complex& other )
	{
		this->real = other.real;
		this->imag = other.imag;
	}
	Complex& operator=( const Complex& other )
	{
		this->real = other.real;
		this->imag = other.imag;
		return *this;
	}
	friend ostream& operator<<( ostream& cout, const Complex& other )
	{
		cout<<"Real	:	"<<other.real<<endl;
		cout<<"Imag	:	"<<other.imag<<endl;
		return cout;
	}
};
int main( void )
{
	Complex c1( 10, 20 );
	Complex c2;
	Complex c3;

	c3 = c2 = c1;	//c2.operator=(c1)

	cout<< c3 <<endl;
	return 0;
}
