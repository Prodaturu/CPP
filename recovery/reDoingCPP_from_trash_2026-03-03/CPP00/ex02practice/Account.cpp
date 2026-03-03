#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* --- Constructor & Destructor --- */

// --- Default constructor --- //
// Defined to avoid linker errors.
Account::Account( void ) // private & isn't used in this project
{
	// As it is new account it means we have one more account
	_accountIndex = _nbAccounts++; // 0 to n-1 are occupied and new account gets n
	_amount = 0; // since no deposit its 0
	_nbDeposits = 0; // since no deposit its 0
	_nbWithdrawals = 0; // since no withdrawal its 0
	_displayTimestamp(); // display timestamp
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

// --- Constructor when initial deposit is given --- //
Account::Account( int initial_deposit )
{
	// Initialize instance variables
	_accountIndex = _nbAccounts++; // 0 to n-1 are occupied and new account gets n
	_amount = initial_deposit;	// since first deposit its initial_deposit
	_nbDeposits = 0; // no deposits yet
	_nbWithdrawals = 0; // no withdrawals yet
	_totalAmount += initial_deposit; // update total amount across all accounts
	
	// Display creation message
	_displayTimestamp(); // display timestamp
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl; // display info of new account
}

// --- Destructor --- //
Account::~Account(void)
{
	// Update total statistics //
	_totalAmount -= this->_amount;
	_nbAccounts--;

	// Display closure message //
	_displayTimestamp(); // display timestamp
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "closed" << std::endl;
}

/* --- Getter Functions --- */
int		Account::getNbAccounts(void) {return _nbAccounts;}
int		Account::getTotalAmount(void) {return _totalAmount;}
int		Account::getNbDeposits(void) {return _totalNbDeposits;}
int		Account::getNbWithdrawals(void) {return _totalNbWithdrawals;}

void	Account::displayAccountsInfos(void)
{
	// Display summary of all accounts together //
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

/* --- Setter Functions --- */
void	Account::makeDeposit(int deposit)
{
	// ignore non-positive deposits
	if (deposit <= 0)
		return;
	
	int prevAmount = this->_amount; // previous amount before deposit

	// Update account-specific statistics
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit; // update total amount across all accounts

	// Display deposit message
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << prevAmount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits << std::endl;

	// Note: "p_amount" is previous amount before deposit
	// "amount" is current amount after deposit
	// "nb_deposits" is number of deposits made

	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	// ignore non-positive withdrawals
	if (withdrawal <= 0)
		return false;
	
	int prevAmount = _amount; // previous amount before withdrawal

	// Check if sufficient funds are available
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << prevAmount << ";"
			<< "withdrawal:refused" << std::endl;
		return false; // withdrawal refused	
	}
	// --- We reach here only if withdrawal will be successful --- //

	// Update account-specific statistics
	_amount -= withdrawal;
	_nbWithdrawals++;
	
	// update total amount across all accounts
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	// Display withdrawal message
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << prevAmount << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true; // withdrawal successful
}

int		Account::checkAmount(void) const
{
	return  _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(nullptr);
	std::tm tm = *std::localtime(&t);
	std::cout << "[" << std::put_time(&tm, "%Y%m%d_%H%M%S") << "] ";
}
