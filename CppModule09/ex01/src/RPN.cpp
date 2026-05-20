/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:34:50 by lserodon          #+#    #+#             */
/*   Updated: 2026/05/20 14:03:13 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) : numbers(other.numbers) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->numbers = other.numbers;
	return (*this);
}

int isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (1);
	return (0);
}

void RPN::parseOperation(char *argv)
{
	std::string operation = argv;

	for (size_t i = 0; i < operation.size(); i++)
	{
		if (argv[i] == ' ')
			continue;
		else if (isdigit(argv[i]) != 0)
		{
			if (argv[i + 1] != ' ')
			{		
				std::cerr << "Error " << std::endl;
				return ;
			}
			this->numbers.push(argv[i] - '0');
		}
		else if (isOperator(argv[i]))
		{
			if (numbers.size() < 2)
			{
				std::cerr << "Error : stack too small" << std::endl;
				return ;
			}
			if (argv[i + 1] != ' ' && argv[i + 1] != '\0')
			{
				std::cerr << "Error sign : " << argv[i] << std::endl;
				return ;
			}
			calculateOperation(argv[i]);
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	if (numbers.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	std::cout << numbers.top() << std::endl;
}

void	RPN::calculateOperation(char sign)
{
	double 	temp = numbers.top();
	double	res;

	numbers.pop();
	
	if (sign == '/' && temp == 0)
		throw std::runtime_error("Error: division by zero");

	double top = numbers.top();
		
	if (sign == '+') {
		if ((temp > 0 && top > INT_MAX - temp) ||
			(temp < 0 && top < INT_MIN - temp))
			throw std::runtime_error("Error: integer overflow");
		res = top + temp;
	}
	else if (sign == '-') {
		if ((temp < 0 && top > INT_MAX + temp) ||
			(temp > 0 && top < INT_MIN + temp))
			throw std::runtime_error("Error: integer overflow");
		res = top - temp;
	}
	else if (sign == '/') {
		if (top == INT_MIN && temp == -1)
			throw std::runtime_error("Error: integer overflow");
		res = top / temp;
	}
	else if (sign == '*') {
		if (temp != 0 && (top > INT_MAX / temp || top < INT_MIN / temp))
			throw std::runtime_error("Error: integer overflow");
		res = top * temp;
	}
	numbers.pop();
	numbers.push(res);
}