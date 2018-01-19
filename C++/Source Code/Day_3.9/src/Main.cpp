#include<iostream>
using namespace std;

#include"../include/Complex.h"
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
	try
	{
		int choice;
		Complex Complex;
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
	}
	catch( Exception& ex)
	{
		cout<<ex.getMessage()<<endl;
	}
	catch(...)
	{
		cout<<"Exception"<<endl;
	}
	return 0;
}
