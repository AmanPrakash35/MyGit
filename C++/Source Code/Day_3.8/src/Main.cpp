#include<iostream>
#include<string>
using namespace std;
namespace nexception
{
	class Exception
	{
	private:
		const string message;
	public:
		Exception( const string message = "" ) : message( message )
		{	}
		string getMessage( void )const
		{
			return this->message;
		}
	};
}
using namespace nexception;
namespace ncomplex
{
	class Complex
	{
	private:
		int real;
		int imag;
	public:
		Complex( const int real = 0, const int imag = 0) throw( Exception )
		{
			this->setReal(real);
			this->setImag(imag);
		}
		int getReal( void )const throw( )
		{
			return this->real;
		}
		void setReal( const int real )throw( Exception )
		{
			if( real >= 0 )
				this->real = real;
			else
				throw Exception("Invalid real number");
		}
		int getImag( void )const throw( )
		{
			return this->imag;
		}
		void setImag( const int imag )throw( Exception )
		{
			if( imag >= 0 )
				this->imag = imag;
			else
				throw Exception("Invalid imag number");
		}
	};//end of class
}//end of namespace

using namespace ncomplex;
void accept_record( Complex& c1 )throw( Exception )
{
	int real;
	cout<<"Enter real number	:	";
	cin>>real;
	c1.setReal( real);

	int imag;
	cout<<"Enter imag number	:	";
	cin>>imag;
	c1.setImag( imag );
}
void print_record( const Complex& c1 )throw( )
{
	int real = c1.getReal();
	cout<<"Real	:	"<<real<<endl;

	int imag = c1.getImag();
	cout<<"Imag	:	"<<imag<<endl;
}
int menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Accept Record"<<endl;
	cout<<"2.Print Record"<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	int choice;
	Complex Complex( -100,-200);
	while( ( choice = menu_list( ) ) != 0 )
	{
		try
		{
			switch( choice )
			{
			case 1:
				::accept_record(Complex);
				break;
			case 2:
				::print_record(Complex);
				break;
			}
		}
		catch(Exception& ex)
		{
			cout<<ex.getMessage()<<endl;
		}
	}
	return 0;
}
