#include "Account.hpp"
#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string_view>
#include <limits>
#include <sstream>

std::string	prepareDateFormat(int date)
{
	std::string	formatted;
	std::ostringstream stringstream;
	
	stringstream << date;
	formatted = stringstream.str();
	formatted = (formatted.length() < 2 ? "0" + formatted : formatted);

	return (formatted);
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{	
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();

	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	
	this->_accountIndex = getNbAccounts();
	this->_amount = initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += this->checkAmount();
}

Account::~Account( void )
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->checkAmount() << ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;

	return (true);
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		timestamp;
	struct tm	*datetime;

	time(&timestamp);
	datetime = gmtime(&timestamp);
	
	std::cout << "[";
	std::cout << 1900 + datetime->tm_year;
	std::cout << prepareDateFormat(datetime->tm_mon + 1);
	std::cout << prepareDateFormat(datetime->tm_mday);
	std::cout << "_";
	std::cout << prepareDateFormat(datetime->tm_hour + 2);
	std::cout << prepareDateFormat(datetime->tm_min);
	std::cout << prepareDateFormat(datetime->tm_sec);
	std::cout << "] ";
}

Account::Account( void )
{
	;
}