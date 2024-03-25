#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits ++;
	_totalNbDeposits += _nbDeposits;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << "\n";

}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout<< "p_amount:" << this->_amount << ";";
	this->_amount -= withdrawal;
	if (checkAmount())
	{
		this->_amount += withdrawal;
		std::cout << "withdrawal:refused" << "" << "\n";
		return false;
	}
	this->_nbWithdrawals ++;
	_totalNbWithdrawals += _nbWithdrawals;
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
	return true;
}

int	Account::checkAmount( void ) const
{
	return (this->_amount <= 0);
}
void	 Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::_displayTimestamp(void)
{
	time_t			start;
	struct tm* 		tm;
	
	start = time(0);
  	tm = localtime ( &start );
	std::cout << "[";
	std::cout << tm->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_mday;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_mon + 1;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_min;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_sec;
	std::cout << "]";
}
Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout<< "amount:" << this->_amount << ";" << "created" << "\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" <<  _accountIndex  << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << "\n";
}