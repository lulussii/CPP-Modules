/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:03:32 by lserodon          #+#    #+#             */
/*   Updated: 2026/05/06 09:06:38 by lserodon         ###   ########.fr       */
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
		throw std::runtime_error("Error: Data file doesn't exist");

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

int StringtoInt(std::string str)
{
	std::stringstream ss(str);
	int res;
	ss >> res;
	return res;
}

void	splitDate(std::string date)
{
	int year = StringtoInt(date.substr(0, 4));
	int month = StringtoInt(date.substr(5, 2));
	int day = StringtoInt(date.substr(8, 2));

	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
		throw BadInputException(date);
	if (month < 1 || month > 12)
		throw BadInputException(date);
	
	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDays = daysInMonth[month];
	
	if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
		maxDays = 29;
		
	if (day < 1 || day > maxDays)
		throw BadInputException(date);
}

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
	splitDate(date);
}

float checkValue(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((isdigit(str[i]) == 0) && str[i] != '.')
			throw BadInputException(str);
	}
	float value = static_cast<float>(std::atof(str.c_str()));
	if (value < 0)
		throw std::runtime_error("Error: not a positive number.");
	else if (value > 1000)
		throw std::runtime_error("Error: too large a number.");
	return (value);
}

void BitcoinExchange::displayLine(std::string date, float value)
{
	std::map<std::string, float>::iterator it = this->data.lower_bound(date);

	if (it == this->data.begin() && it->first != date)
		throw std::runtime_error ("Error: date too old " + date);
	if (it == this->data.end() || it->first != date)
		--it;

	std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
}

void BitcoinExchange::parseFile(char *argv)
{
	std::ifstream file(argv);
	if (!file)
		throw std::runtime_error ("Error: The file doesn't exist");
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw std::runtime_error("Error");
	while (std::getline(file, line))
	{
		try 
		{
			if (line.size() < 14)
				throw BadInputException(line);
			checkDate(line.substr(0,10));
			if (line.substr(10, 3) != " | ")
				throw BadInputException(line);
			float value = checkValue(line.substr(13));
			displayLine(line.substr(0, 10), value);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
