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

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
}
Account::~Account( void )
{

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

int	Account::getNbAccounts( void )
{
	int	count;

	return (count);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();

	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
	std::cout << std::endl;
}


void	Account::displayStatus( void ) const
{

}