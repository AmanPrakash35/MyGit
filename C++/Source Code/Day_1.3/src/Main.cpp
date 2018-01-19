#include<iostream>
using namespace std;
namespace naccount
{
	class Account
	{
	private:
		char name[ 30 ];
		int accountNumber;
		float balance;
	public:
		void acceptRecord( void )
		{
			cout<<"Name	:	";
			cin>>name;
			cout<<"Account Number	:	";
			cin>>accountNumber;
			cout<<"Balance	:	";
			cin>>balance;
		}
		void printRecord( void )
		{
			cout<<"Name	:	"<<name<<endl;
			cout<<"Account Number	:	"<<accountNumber<<endl;
			cout<<"Balance	:	"<<balance<<endl;
		}
	};
}
int main( void )
{
	//naccount::Account account;

	using namespace naccount;
	Account account;

	//account.acceptRecord();
	account.Account::acceptRecord();

	//account.printRecord();
	account.Account::printRecord();
	return 0;
}


/*//int x = a;
//int y = b;
void calculate( int x, int y, int* ptrSum, int* ptrSub )
{
	*ptrSum = x + y;
	*ptrSub = x - y;
}
int main( void )
{
	int a = 10;
	int b = 20;
	int resSum;
	int resSub;
	calculate( a, b, &resSum, &resSub );
	return 0;
}*/
