#include<iostream>
#include<string>
using namespace std;
class Product
{
private:
	string title;
	float price;
public:
	Product( void ) : title( "" ), price( 0 )
	{	}
	virtual void acceptRecord( void )
	{
		cout<<"Title	:	";
		cin>>this->title;
		cout<<"Price	:	";
		cin>>this->price;
	}
	virtual void printRecord( void )
	{
		cout<<"Title	:	"<<this->title<<endl;
		cout<<"Price	:	"<<this->price<<endl;
	}
};
class Book : public Product
{
private:
	int pageCount;
public:
	Book( void ) : pageCount( 0 )
	{	}
	virtual void acceptRecord( void )
	{
		Product::acceptRecord();
		cout<<"Page Count	:	";
		cin>>this->pageCount;
	}
	virtual void printRecord( void )
	{
		Product::printRecord();
		cout<<"Page Count	:	"<<this->pageCount<<endl;
	}
};
class Tape : public Product
{
private:
	int playTime;
public:
	Tape( void ) : playTime( 0 )
	{	}
	virtual void acceptRecord( void )
	{
		Product::acceptRecord();
		cout<<"Play Time	:	";
		cin>>this->playTime;
	}
	virtual void printRecord( void )
	{
		Product::printRecord();
		cout<<"Play Time	:	"<<this->playTime<<endl;
	}
};
class ProductFactory
{
public:
	static Product* getInstance( int choice )
	{
		Product* ptr = NULL;
		switch( choice )
		{
		case 1:
			ptr = new Book();
			break;
		case 2:
			ptr = new Tape();
			break;
		}
		return ptr;
	}
};
int menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Book"<<endl;
	cout<<"2.Tape"<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return choice;
}
int main( void )
{
	int choice;
	while( ( choice = ::menu_list( ) ) != 0 )
	{
		Product* ptr = ProductFactory::getInstance(choice);
		if( ptr != NULL )
		{
			ptr->acceptRecord();
			ptr->printRecord();
		}
		delete ptr;
	}
	return 0;
}
