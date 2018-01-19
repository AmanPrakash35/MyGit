#include<iostream>
using namespace std;

class Base
{
private:
	int num1;
	int num2;
public:
	Base( void )
	{
		this->num1 = 10;
		this->num2 = 20;
	}
	Base( const int num1, const int num2 )
	{
		this->num1 = num1;
		this->num2 = num2;
	}
	void showRecord( void )
	{
		cout<<"Num1	:	"<<this->num1<<endl;
		cout<<"Num2	:	"<<this->num2<<endl;
	}
	void printRecord( void )
	{
		this->showRecord();
	}
};
class Derived : public Base
{
private:
	int num3;
public:
	Derived( void )
	{
		this->num3 = 30;
	}
	Derived( const int num1, const int num2, const int num3 )
	:Base( num1, num2 )
	{
		this->num3 = num3;
	}
	void displayRecord( void )
	{
		Base::showRecord();
		cout<<"Num3	:	"<<this->num3<<endl;
	}
	void printRecord( void )
	{
		this->displayRecord();
	}
};
/*int main( void )
{
	Base base;
	//base.showRecord();			//Base::showRecord
	//base.printRecord();			//Base::printRecord
	//base.displayRecord();			//Error
	//base.Derived::printRecord();	//Error
	return 0;
}*/
/*int main( void )
{
	Base* ptrBase = new Base();
	//ptrBase->showRecord();			//Base::showRecord
	//ptrBase->printRecord();			//Base::printRecord
	//ptrBase->displayRecord();			//Error
	//ptrBase->Derived::printRecord();	//Error
	delete ptrBase;
	return 0;
}*/
/*int main( void )
{
	Derived derived;
	//derived.showRecord();			//Base::showRecord
	//derived.printRecord();		//Derived::printRecord
	//derived.Base::printRecord();	//Base::printRecord
	//derived.displayRecord();		//Derived::displayRecord
	return 0;
}*/

/*int main( void )
{
	Derived* ptrDerived = new Derived();
	//ptrDerived->showRecord();			//Base::showRecord
	//ptrDerived->printRecord();		//Derived::printRecord
	//ptrDerived->Base::printRecord();	//Base::printRecord
	//ptrDerived->displayRecord();		//Derived::displayRecord
	delete ptrDerived;
	return 0;
}*/

/*int main( void )
{
	Base base;
	Derived derived( 500,600,700);
	base = derived;	//Object Slicing
	base.printRecord();	//Base::printRecord --> 500, 600
	return 0;
}*/

/*int main( void )
{
	Derived derived;
	Base base(500,600);
	derived  = base;	//Error
	base.printRecord();
	return 0;
}*/

/*int main( void )
{
	Derived* ptrDerived = new Derived( );
	ptrDerived->printRecord();

	//Base* ptrBase = ( Base* )ptrDerived;	//Upcasting
	Base* ptrBase = ptrDerived;	//Upcasting
	ptrBase->printRecord();

	delete ptrDerived;
	return 0;
}*/

int main( void )
{
	Base* ptrBase = new Derived();	//Upcasting
	ptrBase->showRecord();

	Derived* ptrDerived = ( Derived* )ptrBase;	//Downcasting
	ptrDerived->displayRecord();

	delete ptrDerived;
	return 0;
}
