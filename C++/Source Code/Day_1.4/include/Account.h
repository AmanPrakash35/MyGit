/*
 * Account.h
 *
 *  Created on: 24-Aug-2017
 *      Author: sandeep
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

namespace naccount
{
	class Account
	{
	private:
		char name[ 30 ];
		int accountNumber;
		float balance;
	public:
		void acceptRecord( void );

		void printRecord( void );
	};
}//end of namespace

#endif /* ACCOUNT_H_ */
