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
		this->real = 10;
		this->imag = 20;
	}
	friend ostream& operator<<( ostream& cout,const Complex& other )
	{
		cout<<"Real	:	"<<other.real<<endl;
		cout<<"Imag	:	"<<other.imag<<endl;
		return cout;
	}
};
int main( void )
{
	Complex c1;
	cout<<c1<<endl;

	Complex* ptrComplex = &c1;
	int* ptr = reinterpret_cast<int*>( ptrComplex );
	*ptr = 500;
	ptr = ptr + 1;
	*ptr = 600;

	cout<<c1<<endl;
	return 0;
}
