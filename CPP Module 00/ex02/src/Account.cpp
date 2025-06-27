/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 08:05:03 by lserodon          #+#    #+#             */
/*   Updated: 2025/06/26 14:37:55 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::checkAmount() const
{
	return(_amount);
}

void	Account::_displayTimestamp( void )
{
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
	char output[16];

	strftime(output, 16, "%Y%m%d_%H%M%S", &datetime);
	std::cout << "[" << output << "] ";
}

Account::Account( int initial_deposit)
{
	Account::_nbAccounts++;
	_accountIndex = Account::_nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << checkAmount() << ";created\n"; 
}

Account::~Account()
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << checkAmount() << ";closed\n"; 
}

void	Account::displayAccountsInfos (void)
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::displayStatus(void) const 
{
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "amount:" << checkAmount() << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << "\n";
}

void	Account::makeDeposit(int deposit)
{
	int p_amount;
	
	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int p_amount;
	
	p_amount = _amount;
	_displayTimestamp();
	if (_amount - withdrawal < 0)
	{
		std::cout 	<< "index:" << _accountIndex << ";"
					<< "p_amount:" << p_amount << ";"
					<< "withdrawal:refused\n";
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		std::cout	<< "index:" << _accountIndex << ";"
					<< "p_amount:" << p_amount << ";"
					<< "withdrawal:" << withdrawal << ";"
					<< "amount:" << checkAmount() << ";"
					<< "nb_withdrawals:" << _nbWithdrawals << "\n";
		return (true);
	}	
}