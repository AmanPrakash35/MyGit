#include<iostream>
using namespace std;

#include"../include/Exception.h"
using namespace nexception;

Exception::Exception( const string message, const string fileName , const string functionName,  const int lineNumber ) : message( message ), fileName(fileName),functionName( functionName), lineNumber( lineNumber)
{	}
void Exception::printStackTrace( void )const
{
	cout<<"Exception : "<<this->message<<endl;
	cout<<"In "<<this->fileName<<" : "<<this->functionName<<" ";
	cout<<"at line number "<<this->lineNumber<<endl;
}
