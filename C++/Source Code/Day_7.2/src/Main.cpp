#include<cstring>
#include<iostream>
#include<string>
using namespace std;
class ArrayIndexOutOfBoundsException
{
private:
	const string message;
public:
	ArrayIndexOutOfBoundsException( const string message = "Array index out of bouds exception " ) : message( message )
	{	}
	const string getMessage( void )const throw( )
	{
		return this->message;
	}
};
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
	Array( const size_t size )throw( bad_alloc )
	{
		this->size = size;
		this->arr = new int[ this->size ];
	}
	Array( const Array& other )throw( bad_alloc )
	{
		this->size = other.size;
		this->arr = new int[ this->size ];
		memcpy(this->arr, other.arr, sizeof( int ) * this->size );
	}
	Array& operator=( const Array& other )
	{
		this->~Array();
		this->size = other.size;
		this->arr = new int[ this->size ];
		memcpy(this->arr, other.arr, sizeof( int ) * this->size );
		return *this;
	}
	int& operator[]( const int index )throw( ArrayIndexOutOfBoundsException )
	{
		if( index >= 0 && index < this->size )
			return this->arr[ index ];
		throw ArrayIndexOutOfBoundsException();
	}
	~Array( void )
	{
		if( this->arr != NULL )
		{
			delete[] this->arr;
			this->arr = NULL;
		}
	}
	friend istream& operator>>( istream& cin, Array& other )
	{
		for( int index = 0; index < other.size; ++ index )
		{
			cout<<"Enter number	:	";
			cin>>other.arr[ index ];
		}
		return cin;
	}
	friend ostream& operator<<( ostream& cout, Array& other )
	{
		for( int index = 0; index < other.size; ++ index )
		{
			cout<<other.arr[ index ]<<endl;
		}
		return cout;
	}
};
/*int main( void )
{
	Array a1( 3 ),a2( 2 );
	cin>>a1;	//operator>>( cin, a1 );
	a2 = a1;	//a2.operator=( a1 )
	cout<<a2;	//operator<<( cout, a2);
	return 0;
}*/
/*int main( void )
{
	Array a1( 3 );
	cin>>a1;
	int value = a1[ 3 ];	//int value = a1.operator[]( 1 );
	cout<<"Value	:	"<<value<<endl;
	return 0;
}*/
int main( void )
{
	Array a1( 3 );
	a1[ 1 ] = 20;
	cout<<a1;
	return 0;
}
