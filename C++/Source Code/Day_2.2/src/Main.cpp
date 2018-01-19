#include<iostream>
using  namespace std;

namespace ncomplex
{
	class Complex
	{
	private:
		int real ;
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
		void acceptRecord( void )
		{
			cout<<"Real	:	";
			cin>>this->real;
			cout<<"Imag	:	";
			cin>>this->imag;
		}
		void printRecord( void )//void printRecord( /* Complex* const this */ )
		{
			cout<<"Real	:	"<<this->real<<endl;
			cout<<"Imag	:	"<<this->imag<<endl;
		}
	};
}
int main( void )
{
	using namespace ncomplex;

	Complex c1;
	c1.printRecord();

	Complex c2(10,20);
	c2.printRecord();

	return 0;
}

