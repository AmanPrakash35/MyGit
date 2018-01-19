/*
 * Stack.h
 *
 *  Created on: 02-Sep-2017
 *      Author: sandeep
 */

#ifndef STACK_H_
#define STACK_H_

#include"../include/Exception.h"

template<class T>
class Stack
{
private:
	int top;
	int size;
	T* arr;
public:
	Stack( void ) throw( bad_alloc )
	{
		this->top = -1;
		this->size = 5;
		this->arr = new T[ this->size ];
	}
	bool empty( void )const throw( )
	{
		return this->top == -1;
	}
	bool full( void )const throw( )
	{
		return this->top == this->size - 1;
	}
	void push( const T data )throw( Exception )
	{
		if( this->full( ) )
			throw Exception("Stack is full");
		this->arr[ ++ this->top ] = data;
	}
	T peek( void )const throw( Exception )
	{
		if( this->empty() )
			throw Exception("Stack is empty");
		return this->arr[ this->top ];
	}
	void pop( void )throw( Exception )
	{
		if( this->empty() )
			throw Exception("Stack is empty");
		-- this->top;
	}
	~Stack( void )
	{
		if( this->arr != NULL )
		{
			delete[] this->arr;
			this->arr = NULL;
		}
	}
};


#endif /* STACK_H_ */
