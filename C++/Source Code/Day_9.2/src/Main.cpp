#include<iostream>
#include<string>
using namespace std;

class Staff
{
private:
	string name;
	int staffId;
protected:
	float salary;
public:
	Staff( void ) throw( ) : name( "" ), staffId( 0 ), salary( 0 )
	{	}
	virtual void acceptRecord( void )throw( )
	{
		cout<<"Name	:	";
		cin>>this->name;
		cout<<"Id	:	";
		cin>>this->staffId;
	}

	virtual void calculateSalary( void ) = 0;

	void printRecord( void )const throw( )
	{
		cout<<"Name	:	"<<this->name<<endl;
		cout<<"Id	:	"<<this->staffId<<endl;
		cout<<"Salary	:	"<<this->salary<<endl;
	}
	virtual ~Staff( void ){	}
};
class TeachingStaff : public Staff
{
private:
	int theorySessionCount;
public:
	TeachingStaff( void ) : theorySessionCount( 0 )
	{	}
	virtual void acceptRecord( void )throw( )
	{
		Staff::acceptRecord();
		cout<<"Theory Session Count	:	";
		cin>>this->theorySessionCount;
	}
	void calculateSalary( void )
	{
		this->salary = this->theorySessionCount * 750;
	}
};
class NonTeachingStaff : public Staff
{
private:
	int labSessionCount;
public:
	NonTeachingStaff( void ) : labSessionCount( 0 )
	{	}
	virtual void acceptRecord( void )throw( )
	{
		Staff::acceptRecord();
		cout<<"Lab Session Count	:	";
		cin>>this->labSessionCount;
	}
	void calculateSalary( void )
	{
		this->salary = this->labSessionCount * 300;
	}
};
int menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Teaching Staff"<<endl;
	cout<<"2.Non Teaching Staff"<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	int choice;
	while( ( choice = ::menu_list( ) ) != 0 )
	{
		Staff* ptr = NULL;
		switch( choice )
		{
		case 1:
			ptr = new TeachingStaff();	//Upcasting
			break;
		case 2:
			ptr = new NonTeachingStaff();	//Upcasting
			break;
		}
		if( ptr != NULL )
		{
			ptr->acceptRecord();
			ptr->calculateSalary();
			ptr->printRecord();
			delete ptr;
		}
	}
	return 0;
}
