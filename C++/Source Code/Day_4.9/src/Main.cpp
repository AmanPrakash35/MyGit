#include<cstring>
#include<iostream>
using namespace std;

/*
#define size	3
class Array
{
private:
	int arr[ size ];
public:
	Array( void )throw( )
	{
		memset(this->arr, 0, sizeof( int ) *  size );
	}
	void acceptRecord( void )throw( )
	{
		for( int index = 0; index < size; ++ index )
		{
			cout<<"Enter number	:	";
			cin>>this->arr[ index ];
		}
	}
	void printRecord( void )const throw( )
	{
		for( int index = 0; index < size; ++ index )
			cout<<this->arr[ index ]<<endl;
	}
};
int main( void )
{
	Array a1;
	a1.acceptRecord( );
	a1.printRecord( );
	return 0;
}
*/



class Array
{
private:
	size_t size;
	int* arr;
public:
	Array( void )throw( )
	{
		this->size = 0;
		this->arr = NULL;
	}
	Array( size_t size )throw( bad_alloc )
	{
		cout<<"Inside ctor"<<endl;
		this->size = size;
		this->arr = new int[ this->size ];
		memset(this->arr, 0, sizeof( int ) *  size );
	}
	void acceptRecord( void )throw( )
	{
		for( int index = 0; index < size; ++ index )
		{
			cout<<"Enter number	:	";
			cin>>this->arr[ index ];
		}
	}
	void printRecord( void )const throw( )
	{
		for( int index = 0; index < size; ++ index )
			cout<<this->arr[ index ]<<endl;
	}
	 ~Array( void )
	{
		 cout<<"Inside dtor"<<endl;
		if( this->arr != NULL )
		{
			delete[] this->arr;
			this->arr = NULL;
		}
	}
};
int main( void )
{
	Array* ptr = malloc Array( 3 );

	delete ptr;
	return 0;
}
