#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;
/*int main( void )
{
	double number;
	size_t size = sizeof( number );
	cout<<"Size	:	"<<size<<endl;
}
	const type_info& type = typeid( number );
	string typeName = type.name();
	cout<<"Type	:	"<<typeName<<endl;

	int number;
	const type_info& type = typeid( number );
	cout<<"Type	:	"<<type.name()<<endl;

	int number;
	cout<<"Type	:	"<<typeid(number).name()<<endl;
	return 0;
}*/

class Base
{
public:
	virtual void print( void )
	{	}
};
class Derived : public Base
{
public:
	void print( void )
	{	}
};
/*int main( void )
{
	Base base;
	cout<<typeid( base).name()<<endl;
	return 0;
}*/
/*int main( void )
{
	Base* ptrBase = new Base( );
	//cout<<typeid( ptrBase ).name()<<endl;	//P4Base
	cout<<typeid( *ptrBase ).name()<<endl;	//4Base
	return 0;
}*/
/*int main( void )
{
	Derived derived;
	cout<<typeid( derived ).name()<<endl;	//7Derived
	return 0;
}*/
/*int main( void )
{
	Derived* ptr = new Derived();
	cout<<typeid( ptr ).name()<<endl;	//P7Derived
	cout<<typeid( *ptr ).name()<<endl;	//7Derived
	return 0;
}*/
/*int main( void )
{
	Base* ptr = new Derived();
	cout<<typeid( ptr ).name()<<endl;	//P4Base
	//cout<<typeid( *ptr ).name()<<endl;	//4Base	--> if Base class is non polymorphic
	cout<<typeid( *ptr ).name()<<endl;	//7Derived	--> if Base class ispolymorphic
	return 0;
}*/

/*int main( void )
{
	Base* ptr = NULL;
	cout<<typeid( ptr ).name()<<endl;	//P4Base
	cout<<typeid( *ptr ).name()<<endl;	// std::bad_typeid
	return 0;
}*/
