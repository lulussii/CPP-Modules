/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:31:55 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/03 09:51:11 by lserodon         ###   ########.fr       */
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
	void	(Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	int index = -1;

	while (i < 4)
	{
		if (levels[i] == level)
			index = i;
		i++;
	}
	switch (index)
	{
		case 0:
			(this->*functions[0])();
			//fall through
		case 1:
			(this->*functions[1])();;
			//fall through
		case 2:
			(this->*functions[2])();;
			//fall through
		case 3:
			(this->*functions[3])();;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
