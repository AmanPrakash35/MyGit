/*
 * Complex.h
 *
 *  Created on: 25-Aug-2017
 *      Author: sandeep
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include<iostream>
using namespace std;

class Complex
{
private:
	int real;
	int imag;
public:
	inline Complex( void );

	inline void printRecord( void );
};
inline Complex::Complex( void )
{
	this->real = 10;
	this->imag = 20;
}
inline void Complex::printRecord( void )
{
	cout<<"Real	:	"<<this->real<<endl;
	cout<<"Imag	:	"<<this->imag<<endl;
}


#endif /* COMPLEX_H_ */
