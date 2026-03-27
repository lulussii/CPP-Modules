/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:03:32 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/25 15:06:14 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseData(void)
{
	std::ifstream file("data.csv");
	if (!file)
		throw std::runtime_error("Error: Data file don't exist");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
			
		size_t				commaPos = line.find(',');
		if (commaPos != std::string::npos)
		{
			std::stringstream	ss;
			std::string 		date;
			std::string			valueStr;

			date = line.substr(0, commaPos);
			valueStr = line.substr(commaPos + 1);

			float value = static_cast<float>(std::atof(valueStr.c_str()));
			this->data[date] = value;
		}
	}
	file.close();
}