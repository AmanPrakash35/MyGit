#include<iostream>
#include<string>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date( void )
	{
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
	Date( const int day, const int month, const int year )
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	friend istream& operator>>( istream& cin, Date& other )
	{
		cout<<"Enter date : "<<endl;
		cout<<"Day	:	";
		cin>>other.day;
		cout<<"Month	:	";
		cin>>other.month;
		cout<<"Year	:	";
		cin>>other.year;
		return cin;
	}
	friend ostream& operator<<( ostream& cout, const Date& other )
	{
		cout<<other.day<<" / "<<other.month<<" / "<<other.year;
		return cout;
	}
};
class Address
{
private:
	string cityName;
	string stateName;
	int pincode;
public:
	Address( void )
	{
		this->cityName = "";
		this->stateName = "";
		this->pincode = 0;
	}
	Address( const string cityName, const string stateName, const int pincode )
	{
		this->cityName = cityName;
		this->stateName = stateName;
		this->pincode = pincode;
	}
	friend istream& operator>>( istream& cin, Address& other )
	{
		cout<<"Enter Address : "<<endl;
		cout<<"City name	:	";
		cin>>other.cityName;
		cout<<"State name	:	";
		cin>>other.stateName;
		cout<<"Pincode	:	";
		cin>>other.pincode;
		return cin;
	}
	friend ostream& operator<<( ostream& cout, const Address& other )
	{
		cout<<other.cityName<<"  "<<other.stateName<<"  "<<other.pincode;
		return cout;
	}
};
class Person
{
private:
	string name;
	Date birthDate;
	Address currentAddress;
public:
	Person( )
	{	}
	Person( string name, Date birthDate, Address currentAddress ) : name( name ), birthDate( birthDate), currentAddress( currentAddress )
	{	}
	Person( string name, int day, int month, int year , string cityname, string stateName, int pincode ): name( name ), birthDate( day, month, year ),currentAddress( cityname, stateName, pincode )
	{	}
	friend istream& operator>>( istream& cin, Person& other )
	{
		cout<<"Name	:	";
		cin>>other.name;
		cin>>other.birthDate;
		cin>>other.currentAddress;
		return cin;
	}
	friend ostream& operator<<( ostream& cout, const Person& other )
	{
		cout<<"Name		:	"<<other.name<<endl;
		cout<<"BirthDate	:	"<<other.birthDate<<endl;
		cout<<"Address		:	"<<other.currentAddress<<endl;
		return cout;
	}
};
int main( void )
{
/*	Person person;
	cout<<person<<endl;*/

/*	string name = "Amit";
	Date birthDate(12,3,1990);
	Address currentAddress("Mumbai","MAH",12345);
	Person person(name,birthDate,currentAddress);
	cout<<person<<endl;*/


	Person person("Amit",12,3,1990,"Pune","MAH",12345);
	cout<<person<<endl;
	return 0;
}
