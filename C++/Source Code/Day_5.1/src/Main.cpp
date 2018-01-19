#include<iostream>
using namespace std;

class Matrix
{
private:
	size_t row;
	size_t col;
	int** arr;
public:
	Matrix( void )
	{
		this->row = 0;
		this->col = 0;
		this->arr = NULL;
	}
	Matrix( const size_t row, const size_t col )
	{
		this->row = row;
		this->col = col;
		this->arr = new int*[ this->row ];
		for( int index = 0; index < this->row; ++ index )
			this->arr[ index ] = new int[ this->col ];
	}
	void acceptRecord( void )
	{
		for( int row = 0; row < this->row; ++ row )
		{
			for( int col = 0; col < this->col; ++ col )
			{
				cout<<"arr[ "<<row<<" ][ "<<col<<" ] : ";
				cin>>this->arr[ row ][ col ];
			}
		}
	}
	Matrix sum( Matrix m2 )
	{
		Matrix temp( this->row, this->col );
		for( int row = 0; row < this->row; ++ row )
		{
			for( int col = 0; col < this->col; ++ col )
			{
				temp.arr[ row ][ col ] = this->arr[ row ][ col ] + m2.arr[ row ][ col ];
			}
		}
		return temp;
	}
	void printRecord( void )
	{
		for( int row = 0; row < this->row; ++ row )
		{
			for( int col = 0; col < this->col; ++ col )
			{
				cout<<this->arr[ row ][ col ]<<"	";
			}
			cout<<endl;
		}
	}
	~Matrix( void )
	{
		for( int index = 0; index < this->row; ++ index )
			delete[] this->arr[ index ];
		delete[] this->arr;
		this->arr = NULL;
	}
};
int main( void )
{
	Matrix m1( 2, 3 ),m2( 2, 3 );
	m1.acceptRecord();
	m2.acceptRecord();
	Matrix m3 = m1.sum( m2 );
	m3.printRecord();
	return 0;
}
