#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE	5
typedef struct Account
{
	char name[ 30 ];
	int accNumber;
	float balance;
}Account_t;

typedef struct Bank
{
	char bankName[ 30 ];
	char branch[ 30 ];
	Account_t* arr[ SIZE ];
}Bank_t;

void accept_account_info( Account_t* ptrAccount )
{
	printf("Enter account details:\n");
	printf("Name		:	");
	scanf("%s",ptrAccount->name);
	printf("Account No.	:	");
	scanf("%d",&ptrAccount->accNumber);
	printf("Balance		:	");
	scanf("%f",&ptrAccount->balance);
}
void init_bank( Bank_t* ptrBank )
{
	strcpy(ptrBank->bankName, "Citibank N.A.");
	strcpy(ptrBank->branch, "Koregaon, Pune.");
	memset(ptrBank->arr,0, sizeof( Account_t* ) * SIZE );
}
void show_message( const char* message )
{
	printf("%s\n",message);
}
int exist( Bank_t* ptrBank, int accountNumber )
{
	for( int index = 0; index < SIZE; ++ index )
	{
		if( ptrBank->arr[ index ] != NULL )
		{
			if( ptrBank->arr[ index ]->accNumber == accountNumber  )
			{
				return index;
			}
		}
	}
	return -1;
}
int create_account( Bank_t* ptrBank )
{
	int accountCreateStatus = 0;
	if( ptrBank != NULL )
	{
		Account_t* ptrAccount = ( Account_t* )malloc( sizeof( Account_t ) );
		if( ptrAccount != NULL )
		{
			accept_account_info(ptrAccount);
			if( exist(ptrBank, ptrAccount->accNumber) == -1 )
			{
				for( int index = 0; index < SIZE; ++ index )
				{
					if( ptrBank->arr[ index ] == NULL )
					{
						ptrBank->arr[ index ] = ptrAccount;
						accountCreateStatus = 1;
						break;
					}
				}
			}
			else
				free(ptrAccount);
		}
		else
			show_message("Insufficient memory");
		if( accountCreateStatus == 1 )
			return ptrAccount->accNumber;
		else
			return 0;
	}
	return -1;
}
void accept_account_number( const char* message,int* accNumber )
{
	printf("%s	:	",message);
	scanf("%d",accNumber);
}
void accept_amount( float* amount )
{
	printf("Enter amount	:	");
	scanf("%f",amount);
}
float deposit( Bank_t* ptrBank, int accNumber, float amount )
{
	if( ptrBank != NULL )
	{
		int index = exist(ptrBank, accNumber);
		if( index != -1 )
		{
			ptrBank->arr[ index ]->balance += amount;
			return ptrBank->arr[ index ]->balance;
		}
		return 0;
	}
	return -1;
}

float withdraw( Bank_t* ptrBank, int accNumber, float amount )
{
	if( ptrBank != NULL )
	{
		int index = exist(ptrBank, accNumber);
		if( index != -1 )
		{
			ptrBank->arr[ index ]->balance -= amount;
			return ptrBank->arr[ index ]->balance;
		}
		return 0;
	}
	return -1;
}
void print_balance( float* balance )
{
	printf("Updated Balance	is	:	%f\n",*balance);
}
int fund_transfer( Bank_t* ptrBank, int srcAccNumber, int destAccNumber, float amount )
{
	if( ptrBank != NULL )
	{
		int srcIndex = exist(ptrBank, srcAccNumber );
		int destIndex = exist(ptrBank, destAccNumber );
		if( srcIndex != -1 && destIndex != -1 )
		{
			withdraw(ptrBank, srcIndex, amount);
			deposit(ptrBank, destAccNumber, amount);
			return 1;
		}
		return 0;
	}
	return -1;
}
int delete_account( Bank_t* ptrBank, int accNumber )
{
	if( ptrBank != NULL )
	{
		int index = exist(ptrBank, accNumber);
		if( index != -1 )
		{
			free( ptrBank->arr[ index ] );
			ptrBank->arr[ index ] = NULL;
			return 1;
		}
		return 0;
	}
	return -1;
}

void print_bank_info( Bank_t* ptrBank )
{
	printf("-------------------------------------------------------------\n");
	printf("Bank Name	:	%s\n",ptrBank->bankName);
	printf("Branch Name	:	%s\n",ptrBank->branch);
	printf("-------------------------------------------------------------\n");
	for( int index = 0; index < SIZE; ++ index )
	{
		if( ptrBank->arr[ index ] != NULL )
			print_account_info(ptrBank->arr[ index]);
	}
	printf("-------------------------------------------------------------\n");
}

void write_record( Bank_t* ptrBank )	//Save account info in file "accounts.db"
{
	FILE* file = fopen("accounts.db","wb");
	if( file != NULL )
	{
		for( int index = 0; index < SIZE; ++ index )
		{
			if( ptrBank->arr[ index ] != NULL )
			{
				fwrite(ptrBank->arr[ index ], sizeof( Account_t), 1, file);
			}
		}
		fclose(file);
	}
	else
		printf("Error. File read error.\n");
}
void read_record( Bank_t* ptrBank )	//Load account info from file "accounts.db"
{
	FILE* file = fopen("accounts.db","rb");
	if( file != NULL )
	{
		int index = 0;
		while( !feof(file))
		{

			Account_t* ptr = ( Account_t* )malloc( sizeof( Account_t ) );
			fread(ptr, sizeof( Account_t), 1, file);
			if( !feof(file ))	//To avoid stack smashing
				ptrBank->arr[ index ++ ] = ptr;
			else
				free( ptr );
		}
		fclose(file);
	}
	else
		printf("Error. File read error.\n");
}
void print_account_info( Account_t* ptrAccount )
{
	printf("%-20s%-10d%-12.2f\n",ptrAccount->name,ptrAccount->accNumber,ptrAccount->balance);
}
void clear( Bank_t* ptrBank )
{
	for( int index = 0 ;index < SIZE; ++ index )
	{
		if( ptrBank->arr[ index ] != NULL )
			free( ptrBank->arr[ index ] );
	}
}
int menu_list( void )
{
	int choice;
	printf("0.Exit\n");
	printf("1.Create New User.\n");
	printf("2.Deposit amount.\n");
	printf("3.Withdraw amount.\n");
	printf("4.Transfer fund.\n");
	printf("5.Delete account.\n");
	printf("6.Print bank details.\n");
	printf("Enter choice	:	");
	scanf("%d",&choice);
	return choice;
}
int main( void )
{
	int choice;

	Bank_t bank;
	init_bank(&bank);

	read_record(&bank);

	while( ( choice = menu_list( ) ) != 0 )
	{
		int srcAccountNumber,destAccountNumber, transferStatus,deleteStatus;
		float balance,amount;
		switch( choice )
		{
		case 1:
			srcAccountNumber = create_account(&bank);
			srcAccountNumber != -1 ? srcAccountNumber != 0 ? printf("Account is created successfully. Your acc. no is : %d\n",srcAccountNumber) : printf("Error. Account is exist/Account creation failed.\n") : printf("Invalid bank.\n");
			break;
		case 2:
			accept_account_number("Enter account number", &srcAccountNumber);
			accept_amount(&amount);
			balance = deposit(&bank, srcAccountNumber, amount);
			balance != -1 ?  balance != 0 ? print_balance(&balance) : printf("Account does not exist.\n") : printf("Invalid bank\n");
			break;
		case 3:
			accept_account_number("Enter account number", &srcAccountNumber);
			accept_amount(&amount);
			balance = withdraw(&bank, srcAccountNumber, amount);
			balance != -1 ? balance != 0 ? print_balance(&balance) : printf("Account does not exist.\n") : printf("Invalid bank\n");
			break;
		case 4:
			accept_account_number("Enter source account number", &srcAccountNumber);
			accept_account_number("Enter destination account number", &destAccountNumber);
			accept_amount(&amount);
			transferStatus = fund_transfer(&bank, srcAccountNumber, destAccountNumber, amount);
			transferStatus != -1 ? transferStatus == 1 ? printf("Fund is transfered successfully.\n"): printf("Error in Fund Transfer/account does not exist.\n") : printf("Invalid bank\n");
			break;
		case 5:
			accept_account_number("Enter account number", &srcAccountNumber);
			deleteStatus = delete_account(&bank, srcAccountNumber);
			deleteStatus != -1 ? deleteStatus == 1 ? printf("Account is deleted successfully.\n"): printf("Error.Can not delete account/account does not exist.") : printf("Invalid bank.\n");
			break;
		case 6:
			print_bank_info(&bank);
			break;
		}
	}
	write_record(&bank);
	clear( &bank );
	return 0;
}
