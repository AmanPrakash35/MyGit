/*
 * Exception.h
 *
 *  Created on: 25-Aug-2017
 *      Author: sandeep
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

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
		Exception( const string message = "", const string fileName = "", const string functionName = "",  const int lineNumber = 0 );

		void printStackTrace( void )const;
	};
}

#endif /* EXCEPTION_H_ */
