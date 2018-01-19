#include<iostream>
#include<string>
using namespace std;
class Book
{
private:
	string title;
	float price;
	int pageCount;
public:
	Book( void ) : title( "" ), price( 0 ), pageCount( 0 )
	{	}
	void acceptRecord( void )
	{
		cout<<"Title	:	";
		cin>>this->title;
		cout<<"Price	:	";
		cin>>this->price;
		cout<<"Page Count	:	";
		cin>>this->pageCount;
	}
	void printRecord( void )
	{
		cout<<"Title	:	"<<this->title<<endl;
		cout<<"Price	:	"<<this->price<<endl;
		cout<<"Page Count	:	"<<this->pageCount<<endl;
	}
};
int main( void )
{
	Book book;
	book.acceptRecord();
	book.printRecord();
	return 0;
}
