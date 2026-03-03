#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

// Static Members Initialization //
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* --- Constructor & Destructor --- */

//Default constructor
Account::Account() {}

//constructor when initial deposit is given
Account::Account(int initial_deposit)
{
	// Initialize instance variables
	_accountIndex = _nbAccounts; // 0 to n-1 are occupied and new account gets n
	_amount = initial_deposit;	// since first deposit its initial_deposit
	_nbDeposits = 0;
	_nbWithdrawals = 0; // no withdrawals yet

	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->_amount << ";"
	<< "created" << std::endl;
}

// Destructor
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->checkAmount() << ";"
		<< "closed" << std::endl;
}

/* --- Getter Functions --- */

int		Account::getNbAccounts( void ) {return	_nbAccounts;}
int		Account::getTotalAmount( void ) {return _totalAmount;}
int		Account::getNbDeposits( void ) {return _totalNbDeposits;}
int		Account::getNbWithdrawals( void ) {return _totalNbWithdrawals;}

// Display info about all accounts
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

/* --- Setter Functions --- */

void	Account::makeDeposit( int deposit )
{
	if (deposit <= 0)
		return;
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "p_amount:" << p_amount << ";"
	<< "deposit:" << deposit << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= 0)
		return false;
	int p_amount = this->_amount;
	if (withdrawal > this->_amount)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "p_amount:" << p_amount << ";"
	<< "withdrawal:" << withdrawal << ";"
	<< "amount:" << this->_amount << ";"
	<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
	<< "amount:" << this->checkAmount() << ";"
	<< "deposits:" << this->_nbDeposits << ";"
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* --- Helper Functions --- */

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(nullptr);
	std::tm tm = *std::localtime(&t);
	std::cout << "[" << std::put_time(&tm, "%Y%m%d_%H%M%S") << "] ";
}
