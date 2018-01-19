/*#include<iostream>
#include<string>
using namespace std;

void accept_record( int& number )
{
	cout<<"Number	:	";
	cin>>number;
}
void print_record( const int& result )
{
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	cout<<"Open File"<<endl;
	int num1;
	accept_record(num1);

	LABEL:
	int num2;
	accept_record(num2);

	try
	{
		if( num2 == 0 )
		{
			string ex("Divide by zero exception");
			throw ex;
		}
		else
		{
			int result = num1 / num2;
			print_record( result );
		}
	}
	catch( string& ex )
	{
		cout<<ex<<endl;
		goto LABEL;
	}
	cout<<"Close File"<<endl;
	return 0;
}*/


/*#include<iostream>
#include<string>
using namespace std;

void accept_record( int& number )
{
	cout<<"Number	:	";
	cin>>number;
}
void print_record( const int& result )
{
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	cout<<"Open File"<<endl;
	int num1;
	accept_record(num1);

	LABEL:
	int num2;
	accept_record(num2);

	try
	{
		if( num2 == 0 )
			throw string("Divide by zero exception");
		int result = num1 / num2;
		print_record( result );
	}
	catch( string& ex )
	{
		cout<<ex<<endl;
		goto LABEL;
	}
	cout<<"Close File"<<endl;
	return 0;
}*/


#include<iostream>
#include<string>
using namespace std;

namespace nexception
{
	class Exception
	{
	private:
		const string message;
		const string fileName;
		const string functionName;
		const int lineNumber;
	public:
		Exception( const string message = "", const string fileName = "", const string functionName = "",  const int lineNumber = 0 ) : message( message ), fileName(fileName),functionName( functionName), lineNumber( lineNumber)
		{	}
		void printStackTrace( void )const
		{
			cout<<"Exception : "<<this->message<<endl;
			cout<<"In "<<this->fileName<<" : "<<this->functionName<<" ";
			cout<<"at line number "<<this->lineNumber<<endl;
		}
	};
}
void accept_record( int& number )
{
	cout<<"Number	:	";
	cin>>number;
}
void print_record( const int& result )
{
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	cout<<"Open File"<<endl;
	int num1;
	accept_record(num1);

	int num2;
	accept_record(num2);

	try
	{
		if( num2 == 0 )
			throw 0;
			//throw nexception::Exception("Divide by zero exception",__FILE__,__FUNCTION__,__LINE__);
		int result = num1 / num2;
		print_record( result );
	}
	catch( string& ex )
	{
		cout<<ex<<endl;
	}
	catch( nexception::Exception& ex)
	{
		ex.printStackTrace();
	}
	catch(...)
	{
		cout<<"Genric Catch block"<<endl;
	}
	cout<<"Close File"<<endl;
	return 0;
}
