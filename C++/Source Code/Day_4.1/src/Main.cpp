#include<iostream>
#include<stack>
using namespace std;

int main( void )
{
	stack<int> s1;
	s1.push( 10 );
	s1.push( 20 );
	s1.push( 30 );

	while( !s1.empty( ) )
	{
		int element = s1.top();
		cout<<"Popped element	:	"<<element<<endl;
		s1.pop();
	}
	return 0;
}
