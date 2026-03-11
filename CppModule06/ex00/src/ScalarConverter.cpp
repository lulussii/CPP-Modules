/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:50:55 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/11 10:50:46 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) 
{
	(void) other;
	return (*this);
}

int	isPseudoLiteral(std::string &out)
{
	if (out == "-inff" || out == "+inff" || out == "nanf" || out == "-inf" || out == "+inf" || out == "nan")
		return (1);
	return (0);
}

int isChar(std::string &out)
{
	if (out.length() == 1 && !isdigit(out[0]))
		return (1);
	return (0);
}

int isInt(std::string &out)
{
	size_t i = 0;

	if (out[i] == '-' || out[i] == '+')
		i++;
	if (out.length() == 1)
		return (1);
	for (; i < out.length(); i++)
	{
		if (!isdigit(out[i]))
			return (0);
	}
	return (1);
}

int isFloat(std::string &out)
{
	size_t i = 0;
	int	dot = 0;

	if (out[out.length() - 1] != 'f')
		return (0);
	if (out[i] == '-' || out[i] == '+')
		i++;
	for (; i < out.length() - 1; i++)
	{
		if (out[i] == '.' && dot == 0)
			dot = 1;
		else if (isdigit(out[i]))
			continue;
		else
			return (0);
	}
	if (dot == 1)
		return (1);
	return (0);
}

int	isDouble(std::string &out)
{
	size_t i = 0;
	int dot = 0;

	if (out[i] == '-' || out[i] == '+')
		i++;
	for (; i < out.length(); i++)
	{
		if (out[i] == '.' && dot == 0)
			dot = 1;
		else if (isdigit(out[i]))
			continue;
		else
			return (0);
	}
	if (dot == 1)
		return (1);
	return (0);
}

int whichType(std::string out)
{
	if (isPseudoLiteral(out))
		return (PSEUDO);
	else if (isChar(out))
		return (CHAR);
	else if (isInt(out))
		return (INT);
	else if (isFloat(out))
		return (FLOAT);
	else if (isDouble(out))
		return (DOUBLE);
	else 
		return (INVALID);
}

void	convertPseudo(std::string &out)
{
	if (out == "nanf" || out == "nan")
	{
		std::cout << "char: impossible"	<< std::endl;
		std::cout << "int: impossible"	<< std::endl;
		std::cout << "float: nanf" 		<< std::endl;
		std::cout << "double: nan" 		<< std::endl;
	}
	else if (out == "-inff" || out == "-inf")
	{
		std::cout << "char: impossible"	<< std::endl;
		std::cout << "int: impossible"	<< std::endl;
		std::cout << "float: -inff" 	<< std::endl;
		std::cout << "double: -inf" 	<< std::endl;
	}
	else
	{
		std::cout << "char: impossible"	<< std::endl;
		std::cout << "int: impossible"	<< std::endl;
		std::cout << "float: +inff" 	<< std::endl;
		std::cout << "double: +inf" 	<< std::endl;
	}
}

void	convertChar(std::string &out)
{
	char c = out[0];
	if (isprint(c) && !isdigit(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int : " 	<< static_cast<int>(c) 	 	 		<< std::endl;
	std::cout << "float : " << static_cast<float>(c) << ".0f" 	<< std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" 	<< std::endl;
}

void	convertInt(std::string &out)
{
	long value = std::atol(out.c_str());
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " 	<< static_cast<int>(value) 				<< std::endl;
	std::cout << "float: " 	<< static_cast<float>(value) << ".0f" 	<< std::endl;
	std::cout << "double: " << static_cast<double>(value) << ".0"	<< std::endl;
}

void	convertFloat(std::string &out)
{
	float	value = std::atof(out.c_str());
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value == static_cast<int>(value))
		std::cout << "float: " << value << ".0f" << std::endl;
	else
		std::cout << "float: " << value << "f" << std::endl;
	if (value == static_cast<int>(value))
		std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void	convertDouble(std::string &out)
{
	double value = std::atof(out.c_str());
	
	if (value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (isprint(value))
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	
	if (value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	if (value == static_cast<int>(value))
		std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

	if (value == static_cast<int>(value))
		std::cout << "double: " << value << ".0" << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}

void ScalarConverter::convert(std::string out)
{
	int type = whichType(out);
	switch(type)
	{
		case INVALID:
			std::cout << "Invalid input" << std::endl;
			break;
		case PSEUDO:
			convertPseudo(out);
			break;
		case CHAR:
			convertChar(out);
			break;
		case INT:
			convertInt(out);
			break;
		case FLOAT:
			convertFloat(out);
			break;
		case DOUBLE:
			convertDouble(out);
			break;
	}
}
