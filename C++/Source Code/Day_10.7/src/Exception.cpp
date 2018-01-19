#include"../include/Exception.h"

Exception::Exception( const string message) : message( message )
{	}
string Exception::getMessage() const
{
	return this->message;
}
