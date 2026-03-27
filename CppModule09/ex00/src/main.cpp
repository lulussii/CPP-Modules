/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:05:00 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/27 08:50:32 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

//check année correcte
// check tiret
//check mois
//check tiret
//check jour

void checkDate(std::string date)
{
	if (date.length() != 10)
		throw BadInputException(date);
	if (date[4] != '-' || date[7] != '-')
		throw BadInputException(date);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date[i]) == 0)
			throw BadInputException(date);
	}
}

void BitcoinExchange::parseFile(char *argv)
{
	std::ifstream file(argv);
	if (!file)
		throw std::runtime_error ("Error: The file doesn't exist");
	std::string line;
	while (std::getline(file, line))
	{
		checkDate(line.substr(0, 10));
		if (line.substr(10, 3) != " | ")
		{
			std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;

		}
		std::cout << line.substr(0, 10) << " => " << << std::endl;
	}
}

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	(void) argv;
	if (argc != 2)
		std::cout << "The program needs one argument" << std::endl;
	else
	{
		try {
			btc.parseData();
			btc.parseFile(argv[1]);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}