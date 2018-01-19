#include<iostream>
using  namespace std;
namespace ncomplex
{
	class Complex
	{
	private:
		int real;
		int imag;
	public:
		void initComplex( int real, int imag)
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
		//Complex* const this = &c1
		// Complex* ptr = &c2;
		Complex sum( Complex* ptr )
		{
			Complex temp;
			temp.real = this->real + ptr->real;
			temp.imag = this->imag + ptr->imag;
			return temp;
		}

		/*//Complex* const this = &c1
		// Complex other = c2
		Complex sum( Complex other )
		{
			Complex temp;
			temp.real = this->real + other.real;
			temp.imag = this->imag + other.imag;
			return temp;
		}*/
		/*//Complex c1 = c1
		// Complex c2 = c2
		void sum( Complex c1, Complex c2 )
		{
			this->real = c1.real + c2.real;
			this->imag = c1.imag + c2.imag;
		}*/
		void printRecord( void )//void printRecord( /* Complex* const this */ )
		{
			//cout<<"Real	:	"<<real<<endl;
			cout<<"Real	:	"<<this->real<<endl;

			//cout<<"Imag	:	"<<imag<<endl;
			cout<<"Imag	:	"<<this->imag<<endl;
		}
	};
}
/*int main( void )
{
	using namespace ncomplex;
	Complex c1;
	c1.acceptRecord();

	Complex c2;
	c2.acceptRecord();

	Complex c3;
	//c3 = c1 + c2;

	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;

	c3 = c1.sum( &c2 );
	//c3 = c1.sum( c2 );
	//c3.sum( c1, c2);

	c3.printRecord();
	return 0;
}*/


/*int main( void )
{
	using namespace ncomplex;
	Complex arr[ 3 ];

	for( int index = 0; index < 3; ++ index )
		arr[ index ].acceptRecord();

	for( int index = 0; index < 3; ++ index )
		arr[ index ].printRecord();

	return 0;
}*/



int main( void )
{
	int num1 = 10;	//Initialization
	num1 = 20;	//Assignment
	num1 = 30;	//Assignment

	int num2;
	num2 = 10;	//Assignment
	num2 = 20;	//Assignment
	return 0;
}

