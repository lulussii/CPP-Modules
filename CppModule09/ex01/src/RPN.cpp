/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:34:50 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/27 09:04:46 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
				std::cout << "Error " << argv[i] << std::endl;
				return ;
			}
			this->numbers.push(argv[i] - '0');
		}
		else if (isOperator(argv[i]))
		{
			if (numbers.size() < 2)
			{
				std::cout << "Error : stack too small" << std::endl;
				return ;
			}
			if (argv[i + 1] != ' ' && argv[i + 1] != '\0')
			{
				std::cout << "Error sign " << argv[i] << std::endl;
				return ;
			}
			calculateOperation(argv[i]);
		}
		else
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	if (numbers.size() > 1)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	std::cout << numbers.top() << std::endl;
}

void	RPN::calculateOperation(char sign)
{
	int temp = numbers.top();
	int res;

	numbers.pop();
	
	if (sign == '+')
		res = temp + numbers.top();
	else if (sign == '-')
		res = numbers.top() - temp;
	else if (sign == '/')
		res = numbers.top() / temp;
	else if (sign == '*')
		res = numbers.top() * temp;
	numbers.pop();
	numbers.push(res);
}