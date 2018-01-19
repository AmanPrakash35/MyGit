#include"../include/Account.h"
int main( void )
{
	using namespace naccount;
	Account account;

	account.acceptRecord();
	//account.Account::acceptRecord();

	account.printRecord();
	//account.Account::printRecord();

	return 0;
}
