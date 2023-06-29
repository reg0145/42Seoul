#include <time.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static void    PrintTimeStamp()
{
	time_t curTime = time(NULL);
	struct tm *pLocal = localtime(&curTime);

	std::cout << "[";
	std::cout << std::setw(4) << std::setfill('0') << pLocal->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << pLocal->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << pLocal->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << pLocal->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << pLocal->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << pLocal->tm_sec;
	std::cout << "] ";
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbAccounts += 1;
	this->_totalAmount += initial_deposit;
	PrintTimeStamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account() {
	PrintTimeStamp();
	std::cout << "index:" << this->_accountIndex << "amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts() {
	return _nbAccounts;
}

int	Account::getTotalAmount() {
	return _totalAmount;
}

int	Account::getNbDeposits() {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos() {
	PrintTimeStamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	int p_amount     = this->_amount;
	this->_amount    += deposit;
	this->_nbDeposits+= 1;
	_totalAmount     += deposit;
	_totalNbDeposits += 1;
	PrintTimeStamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	int p_amount = this->_amount;
	if (withdrawal > this->_amount) {
		PrintTimeStamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << "refused" << std::endl;
		return false;
	}
	this->_amount        -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalAmount         -= withdrawal;
	_totalNbWithdrawals  += 1;
	PrintTimeStamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount() const{
	return this->_amount > 0;
}

void	Account::displayStatus() const{
	PrintTimeStamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}