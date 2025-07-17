/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 08:42:55 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/03 09:17:01 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout 	<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
				<< "I really do!\n"; 
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout 	<< "I cannot believe adding extra bacon costs more money."
				<< "You didn’t put enough bacon in my burger!"
				<< " If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout 	<< "I think I deserve to have some extra bacon for free. "
				<< "I’ve been coming for years whereas you started working "
				<< "here since last month.\n";
} 

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*functions[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int i;

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
		i++;
	}
}