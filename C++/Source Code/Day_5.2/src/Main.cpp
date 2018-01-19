#include<iostream>
using namespace std;
/*class Test
{
private:
	int num1;
protected:
	int num2;
public:
	Test( void )
	{
		this->num1 = 10;
		this->num2 = 20;
	}
	friend void sum( void );
};
void sum( void )
{
	Test t;
	int result = t.num1 + t.num2;
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	sum( );
	return 0;
}*/

/*class A
{
private:
	int num1;
public:
	A( void )
	{
		this->num1 = 10;
	}
	friend void sum( void );
};
class B
{
protected:
	int num2;
public:
	B( void )
	{
		this->num2 = 20;
	}
	friend void sum( void );
};
void sum( void )
{
	A a; B b;
	int result = a.num1 + b. num2;
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	sum( );
	return 0;
}*/
/*class A
{
public:
	void sum( void );
	void sub( void );
	void multiplication( void );
};
class B
{
private:
	int num1;
protected:
	int num2;
public:
	B( void );
	friend void A::sum( void );
	friend void A::sub( void );
	friend void A::multiplication( void );
};
B::B( void )
{
	this->num1 = 10;
	this->num2 = 20;
}
void A::sum( void )
{
	B obj;
	int result = obj.num1 + obj.num2;
	cout<<"Result	:	"<<result<<endl;
}
void A::sub( void )
{
	B obj;
	int result = obj.num1 - obj.num2;
	cout<<"Result	:	"<<result<<endl;
}
void A::multiplication( void )
{
	B obj;
	int result = obj.num1 * obj.num2;
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	A obj;
	obj.sum();
	obj.sub();
	obj.multiplication();
	return 0;
}*/


/*class A
{
public:
	void sum( void );
	void sub( void );
	void multiplication( void );
};
class B
{
private:
	int num1;
protected:
	int num2;
public:
	B( void );
	friend void A::sum( void );
	friend void A::sub( void );
	friend void A::multiplication( void );
	friend class A;
};
B::B( void )
{
	this->num1 = 10;
	this->num2 = 20;
}
void A::sum( void )
{
	B obj;
	int result = obj.num1 + obj.num2;
	cout<<"Result	:	"<<result<<endl;
}
void A::sub( void )
{
	B obj;
	int result = obj.num1 - obj.num2;
	cout<<"Result	:	"<<result<<endl;
}
void A::multiplication( void )
{
	B obj;
	int result = obj.num1 * obj.num2;
	cout<<"Result	:	"<<result<<endl;
}
int main( void )
{
	A obj;
	obj.sum();
	obj.sub();
	obj.multiplication();
	return 0;
}*/

/*class B;	//Forward declaration
class A
{
private:
	int num1;
public:
	void showRecord( void );
	friend class B;
};
class B
{
protected:
	int num2;
public:
	void displayRecord( void );
	friend class A;
};
void A::showRecord( void )
{
	B obj;
	obj.num2 = 100;
	cout<<"Num2	:	"<<obj.num2<<endl;
}
void B::displayRecord( void )
{
	A obj;
	obj.num1 = 200;
	cout<<"Num1	:	"<<obj.num1<<endl;
}
int main( void )
{
	A a;
	a.showRecord();

	B b;
	b.displayRecord();
	return 0;
}*/

/*namespace ntest
{
	class Test
	{
	private:
		int number;
	public:
		Test( void )
		{
			this->number = 10;
		}
		friend void print( void );
	};
	void print( void )
	{
		Test t;
		cout<<"Number	:	"<<t.number<<endl;
	}
}
int main( void )
{
	ntest::print();
	return 0;
}*/

/*namespace ntest
{
	class Test
	{
	private:
		int number;
	public:
		Test( void )
		{
			this->number = 10;
		}
		friend void print( void );
	};
}
void ntest::print( void )
{
	Test t;
	cout<<"Number	:	"<<t.number<<endl;
}
int main( void )
{
	ntest::print();
	return 0;
}*/


/*class Outer		//Top level class
{
public:
	class Inner	//Nested class
	{

	};
};
int main( void )
{
	Outer out;

	Outer::Inner in;
	return 0;
}*/

/*class Outer		//Top level class
{
private:
	int num1;
	static int num2;
public:
	Outer( void )
	{
		this->num1 = 10;
	}
public:
	class Inner
	{
	private:
		int num3;
		static int num4;
	public:
		Inner( void )
		{
			this->num3 = 30;
		}
		friend class Outer;
	};
public:
	void print( void )
	{
		cout<<"Num1	:	"<<this->num1<<endl;
		cout<<"Num2	:	"<<Outer::num2<<endl;

		Inner in;

		cout<<"Num3	:	"<<in.num3<<endl;
		cout<<"Num4	:	"<<Inner::num4<<endl;
	}
};
int Outer::num2 = 20;
int Outer::Inner::num4 = 40;
int main( void )
{
	Outer out;
	out.print();
	return 0;
}*/


/*class Outer
{
private:
	int num1;
	static int num2;
public:
	Outer( void )
	{
		this->num1 = 10;
	}
public:
	class Inner
	{
	private:
		int num3;
		static int num4;
	public:
		Inner( void )
		{
			this->num3 = 30;
		}
		void print( void )
		{
			Outer out;
			cout<<"Num1	:	"<<out.num1<<endl;
			cout<<"Num2	:	"<<Outer::num2<<endl;

			cout<<"Num3	:	"<<this->num3<<endl;
			cout<<"Num4	:	"<<Inner::num4<<endl;
		}
	};
};
int Outer::num2 = 20;
int Outer::Inner::num4 = 40;
int main( void )
{
	Outer::Inner in;
	in.print();
	return 0;
}*/


int main( void )
{
	class Complex
	{
	private:
		int real;
		int imag;
	public:
		Complex( void )
		{
			this->real = 10;
			this->imag = 20;
		}
		void print( void )
		{
			cout<<"Real	:	"<<this->real<<endl;
			cout<<"Imag	:	"<<this->imag<<endl;
		}
	};
	Complex c1;
	c1.print();
	return 0;
}
