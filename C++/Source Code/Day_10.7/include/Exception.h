/*
 * Exception.h
 *
 *  Created on: 02-Sep-2017
 *      Author: sandeep
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include<string>
using namespace std;

class Exception
{
private:
	string message;
public:
	Exception( const string message = "" );

	string getMessage() const;
};

#endif /* EXCEPTION_H_ */
