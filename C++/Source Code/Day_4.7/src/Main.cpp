#include<iostream>
using namespace std;

int main( void )
{
	int** ptr = new int*[ 2 ];
	for( int index = 0; index < 2; ++ index )
		ptr[ index ] = new int[ 3 ];

	for( int row = 0; row < 2; ++ row )
	{
		for( int col = 0; col < 3; ++ col )
		{
			cout<<"Enter number	:	";
			cin>>ptr[ row ][ col ];
		}
	}
	for( int row = 0; row < 2; ++ row )
	{
		for( int col = 0; col < 3; ++ col )
		{
			cout<<ptr[ row ][ col ]<<"	";
		}
		cout<<endl;
	}
	for( int index = 0; index < 2; ++ index )
		delete[] ptr[ index ];
	delete[] ptr;
	return 0;
}
