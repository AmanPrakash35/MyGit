/*
 * Exception.h
 *
 *  Created on: 26-Aug-2017
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
	public:
		Exception( const string message = "" );

		string getMessage( void )const;
	};
}

#endif /* EXCEPTION_H_ */
