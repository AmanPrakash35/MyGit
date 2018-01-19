/*
#pragma pack(1)
#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	string name;		//24 bytes
	int age;			//4 bytes
public:
	Person( void )
	{
		this->name = "";
		this->age = 0;
	}
	Person( const string name, const int age )
	{
		this->name = name;
		this->age = age;
	}
	void showRecord( void )const
	{
		cout<<"Name	:	"<<this->name<<endl;
		cout<<"Age	:	"<<this->age<<endl;
	}
};
int main( void )
{
	Person person("ABC",23);	//28 bytes
	person.showRecord();
	return 0;
}
*/



/*#pragma pack(1)
#include<iostream>
#include<string>
using namespace std;
class Employee
{
private:
	string name;		//24 bytes
	int age;			//4 bytes
	int empid;			//4 bytes
	float salary;		//4 bytes
public:
	Employee( void )
	{
		this->name = "";
		this->age = 0;
		this->empid = 0;
		this->salary = 0;
	}
	Employee( const string name, const int age, const int empid, const float salary )
	{
		this->name = name;
		this->age = age;
		this->empid = empid;
		this->salary = salary;
	}
	void displayRecord( void )const
	{
		cout<<"Name	:	"<<this->name<<endl;
		cout<<"Age	:	"<<this->age<<endl;
		cout<<"Empid	:	"<<this->empid<<endl;
		cout<<"Salary	:	"<<this->salary<<endl;
	}
};
int main( void )
{
	Employee emp("ABC",23,125,350000);
	emp.displayRecord();
	return 0;
}*/



#pragma pack(1)
#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
	string name;		//24 bytes
	int age;	//4 bytes
public:
	Person( void )
	{
		this->name = "";
		this->age = 0;
	}
	Person( const string name, const int age )
	{
		this->name = name;
		this->age = age;
	}
	void showRecord( void )const
	{
		cout<<"Name	:	"<<this->name<<endl;
		cout<<"Age	:	"<<this->age<<endl;
	}
	void printRecord( void )const
	{
		cout<<"Name	:	"<<this->name<<endl;
		cout<<"Age	:	"<<this->age<<endl;
	}
};
//class Employee : Person	//class Employee : private Person
class Employee : public Person
{
private:
	int empid;			//4 bytes
	float salary;		//4 bytes
public:
	Employee( void )
	{
		this->empid = 0;
		this->salary = 0;
	}
	Employee( const string name, const int age, const int empid, const float salary )
	: Person(name, age)	//ctor's base initializer list
	{
		this->empid = empid;
		this->salary = salary;
	}
	void displayRecord( void )const
	{
		//this->showRecord();
		Person::showRecord();
		cout<<"Empid	:	"<<this->empid<<endl;
		cout<<"Salary	:	"<<this->salary<<endl;
	}
	void printRecord( void )const
	{
		//this->Person::printRecord();
		Person::printRecord();
		cout<<"Empid	:	"<<this->empid<<endl;
		cout<<"Salary	:	"<<this->salary<<endl;
	}
};
int main( void )
{
	Employee emp("ABC",23,125,45000);
	emp.printRecord();
	return 0;
}


/*class A
{
public:
	int num1;
public:
	A( void )
	{
		this->num1 = 10;
	}
};
class B : public A
{
public:
	int num1;
public:
	B( void )
	{
		this->num1 = 20;
	}
	void print( void )
	{
		cout<<"A::num1	:	"<<A::num1<<endl;
		cout<<"B::num1	:	"<<this->num1<<endl;
	}
};
int main( void )
{
	B obj;
	obj.print();
	return 0;
}*/
