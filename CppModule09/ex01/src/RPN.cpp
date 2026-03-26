/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:34:50 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/26 13:51:59 by lserodon         ###   ########.fr       */
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
			this->numbers.push(argv[i]);
		}
		else if (isOperator(argv[i]) != 0 && numbers.size() < 2)
		{
			if (argv[i + 1] != ' ' && argv[i + 1] != '\0')
			{
				std::cout << "Error sign " << argv[i] << std::endl;
				return ;
			}
			
		}
		else
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
}

void	RPN::calculateOperation(void)
{
	
}