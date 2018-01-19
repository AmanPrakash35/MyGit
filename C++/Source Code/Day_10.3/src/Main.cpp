#include<iostream>
using namespace std;
class Test
{
private:
	int number;
public:
	Test( void )
	{
		this->number = 10;
	}
	//Test* const this;
	void showRecord( void )
	{
		cout<<this->number<<endl;
	}
	//const Test* const this;
	void printRecord( void )const
	{
		Test* const ptr = const_cast< Test* const  >( this );
		ptr->showRecord();
	}
};
int main( void )
{
	const Test t;
	t.printRecord();
	return 0;
}
