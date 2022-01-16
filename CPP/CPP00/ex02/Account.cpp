#include <ctime>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits << ";withdrawals:"
			<< _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex
			<< ";amount:"<< _amount
			<< ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"<< _amount
		<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	int p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:"
		<< p_amount << ";deposit:" << deposit << ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	int p_amount = _amount;

	if (_amount < withdrawal)
	{
		std::cout
				<< "index:" << _accountIndex << ";p_amount:"
				<< p_amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	_totalAmount -=withdrawal;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_nbWithdrawals++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
			<< "index:" << _accountIndex << ";amount:" << _amount
			<< ";deposits:" << _nbDeposits << ";withdrawals:"
			<< _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	char       buf[80];
	time_t now = time(0);
	tm *tm = localtime(&now);

	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", tm);
	std::cout << '[' << buf << "] ";
}

Account::Account(void)
{
}
