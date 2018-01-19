/*
 * Complex.h
 *
 *  Created on: 26-Aug-2017
 *      Author: sandeep
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include"../include/Exception.h"
using namespace nexception;

namespace ncomplex
{
	class Complex
	{
	private:
		int real;
		int imag;
	public:
		Complex( const int real = 0, const int imag = 0) throw( Exception );

		int getReal( void )const throw( );

		void setReal( const int real )throw( Exception );

		int getImag( void )const throw( );

		void setImag( const int imag )throw( Exception );
	};//end of class
}//end of namespace

#endif /* COMPLEX_H_ */
