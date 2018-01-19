#include<iostream>
using namespace std;

#include"../include/Account.h"
using namespace naccount;

void Account::acceptRecord( void )
{
	cout<<"Name	:	";
	cin>>name;
	cout<<"Account Number	:	";
	cin>>accountNumber;
	cout<<"Balance	:	";
	cin>>balance;
}
void Account::printRecord( void )
{
	cout<<"Name	:	"<<name<<endl;
	cout<<"Account Number	:	"<<accountNumber<<endl;
	cout<<"Balance	:	"<<balance<<endl;
}
