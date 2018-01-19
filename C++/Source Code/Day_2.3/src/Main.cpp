#include<iostream>
using namespace std;

namespace ncomplex
{
	class Complex
	{
	private:
		int real;
		int imag;
	public:
		Complex( void )
		{
			cout<<"Complex( void )"<<endl;
			this->real = 10;
			this->imag = 20;
		}
		Complex( int value )
		{
			cout<<"Complex( int value )"<<endl;
			this->real = value;
			this->imag = value;
		}
		Complex( const Complex& other )	//Copy Ctor
		{
			cout<<"Complex( const Complex& other )"<<endl;
			this->real = other.real;
			this->imag = other.imag;
		}
		Complex( int real, int imag )
		{
			cout<<"Complex( int real, int imag )"<<endl;
			this->real = real;
			this->imag = imag;
		}
		void printRecord( void )
		{
			cout<<"Real	:	"<<this->real<<endl;
			cout<<"Real	:	"<<this->imag<<endl;
		}
	};
}
int main( void )
{
	using namespace ncomplex;

	//Complex* ptr;

	//Complex c1;

	//Complex c2( 10 );

	//Complex c3(20,30);

	//Complex c4();

	//Complex c5 = 40;	//Complex c5 (  40 );

	//Complex( 50, 60 );
	//Complex( 50, 60 ).printRecord();


	//Complex c6 = 70, 80;
	//Complex c6 ( 70 ), 80;


	//Complex c6 = ( 70, 80 );
	//Complex c6 =( 80 );
	//Complex c6( 80 );



	//Complex c7 = { 80, 90 };

	/*Complex c8( 90, 100 );
	Complex c9 = c8;*/

	Complex c8( 90, 100 );
	Complex& c9 = c8;

	return 0;
}
