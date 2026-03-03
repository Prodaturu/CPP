// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {

	private:

		// Static Members - Initialization //
		static int	_nbAccounts; 				// no of accounts created
		static int	_totalAmount; 				// total amount of all accounts
		static int	_totalNbDeposits; 			// total number of deposits
		static int	_totalNbWithdrawals; 		// total number of withdrawals
		static void	_displayTimestamp( void );	// displays timestamp in [YYYYMMDD_HHMMSS] format

		// Instance (non-static) Members //
		int				_accountIndex;		// index of the account
		int				_amount;			// current amount
		int				_nbDeposits;		// number of deposits
		int				_nbWithdrawals;		// number of withdrawals
		
		Account( void );
		
		public:
		
		typedef Account		t;

		static int	getNbAccounts( void );
		static int	getTotalAmount( void );
		static int	getNbDeposits( void );
		static int	getNbWithdrawals( void );
		static void	displayAccountsInfos( void );

		Account( int initial_deposit );
		~Account( void );

		void	makeDeposit( int deposit );
		bool	makeWithdrawal( int withdrawal );
		int		checkAmount( void ) const;
		void	displayStatus( void ) const;

};

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
