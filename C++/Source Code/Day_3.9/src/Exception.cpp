#include"../include/Exception.h"
using namespace nexception;
Exception::Exception( const string message) : message( message )
{	}
string Exception::getMessage( void )const
{
	return this->message;
}
