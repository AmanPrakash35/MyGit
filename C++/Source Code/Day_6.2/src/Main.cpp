#include<cstring>
#include<iostream>
using namespace std;
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
	Array( size_t size )
	{
		this->size = size;
		this->arr = new int[ this->size ];
	}
	//Array* const this = a2
	//const Array& other  = a1
	/*Array( const Array& other )
	{
		this->size = other.size;	//Step 1
		this->arr = new int[ this->size ];	//Step;
		for( int index = 0; index < this->size; ++ index )
			this->arr[ index ] = other.arr[ index ];	//Step 3
	}*/

	/*Array( const Array& other )
	{
		this->size = other.size;	//Step 1
		this->arr = new int[ this->size ];	//Step;
		memcpy(this->arr, other.arr, sizeof( int ) * this->size );//Step 3
	}*/

public:
/*
	Array( const Array& other ) : size( other.size ) , arr( new int[ this->size ])
	{
		memcpy(this->arr, other.arr, sizeof( int ) * this->size );//Step 3
	}
*/
public:
	void acceptRecord( void )
	{
		for( int index = 0; index < size; ++ index )
		{
			cout<<"Enter number	:	";
			cin>>this->arr[ index ];
		}
	}
	void printRecord( void )
	{
		for( int index = 0; index < size; ++ index )
			cout<<this->arr[ index ]<<endl;
	}
	~Array( void )
	{
		if( this->arr != NULL )
		{
			delete[] this->arr;
			this->arr = NULL;
		}
	}
};
int main( void )
{
	Array a1( 3 );
	a1.acceptRecord();
	Array a2 = a1;
	a2.printRecord();
	return 0;
}
