#include<iostream>
using namespace std;

class Base
{
public:
	virtual void f1( void )
	{
		cout<<"Base::f1"<<endl;
	}
	virtual void f2( void )
	{
		cout<<"Base::f2"<<endl;
	}
	virtual void f3( void )
	{
		cout<<"Base::f3"<<endl;
	}
	void f4( void )
	{
		cout<<"Base::f4"<<endl;
	}
	void f5( void )
	{
		cout<<"Base::f5"<<endl;
	}
};
class Derived : public Base
{
public:
	virtual void f1( void )
	{
		cout<<"Derived::f1"<<endl;
	}
	void f2( void )
	{
		cout<<"Derived::f2"<<endl;
	}
	void f4( void )
	{
		cout<<"Derived::f4"<<endl;
	}
	virtual void f5( void )
	{
		cout<<"Derived::f5"<<endl;
	}
	virtual void f6( void )
	{
		cout<<"Derived::f6"<<endl;
	}
};
/*int main( void )
{
	Base base;
	//base.f1();	//Base::f1 --> Early Binding
	//base.f2();	//Base::f2 --> Early Binding
	//base.f3();	//Base::f3 --> Early Binding
	//base.f4();	//Base::f4 --> Early Binding
	//base.f5();	//Base::f5 --> Early Binding
	//base.f6();	//Error : f6 is not a member of class Base
	return 0;
}*/
/*int main( void )
{
	Base* ptr = new Base();
	//ptr->f1();	//Base::f1 --> Late Binding
	//ptr->f2();	//Base::f2 --> Late Binding
	//ptr->f3();	//Base::f3 --> Late Binding
	//ptr->f4();	//Base::f4 --> Early Binding
	//ptr->f5();	//Base::f5 --> Early Binding
	//ptr->f6();//Error : f6 is not a member of class Base
	delete ptr;
	return 0;
}*/
/*int main( void )
{
	Base* ptr = new Derived();	//Upcasting
	//ptr->f1();	//Derived::f1 --> Late Binding
	//ptr->f2();	//Derived::f2 --> Late Binding
	//ptr->f3();	//Base::f3 --> Late Binding
	//ptr->f4();	//Base::f4 --> Early Binding
	//ptr->f5();	//Base::f5 --> Early Binding
	//ptr->f6( );//Error : f6 is not a member of class Base
	delete ptr;
	return 0;
}*/
/*int main( void )
{
	Derived* ptr = new Derived();
	//ptr->f1( );	//Derived::f1 --> Late Binding
	//ptr->f2( );	//Derived::f2 --> Late Binding
	//ptr->f3();	//Base::f3 --> Late Binding
	//ptr->f4();	//Derived::f4 --> Early Binding
	//ptr->f5();	//Derived::f5 --> Late Binding
	//ptr->f6();	//Derived::f6 --> Late Binding
	delete ptr;
	return 0;
}*/
int main( void )
{
	Derived derived;
	Base& base = derived;	//Base* const base = &derived;
	//base.f1();	//Derived::f1 --> Late binding
	//base.f2();	//Derived::f2 --> Late binding
	//base.f3();	//Base::f3 --> Late binding
	//base.f4();	//Base::f4 --> Early binding
	//base.f5();	//Base::f5 --> Early binding
	//base.f6();	//Error
	return 0;
}




