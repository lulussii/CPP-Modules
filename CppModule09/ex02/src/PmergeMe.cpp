/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:06:16 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/30 13:05:41 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isNumber(std::string token)
{
	if (token.empty())
		return (false);
	for (size_t i = 0; i < token.size(); i++)
	{
		if (!isdigit(token[i]))
			return (false);
	}
	return (true);
}

void	PmergeMe::parseNumbers(int argc, char **argv)
{
	std::string allNumbers = "";
	if (argc > 2)
	{
		for (int i = 1; i < argc; i++)
		{
			allNumbers += argv[i];
			allNumbers += " ";
		}
	}
	else
		allNumbers = argv[1];

	std::stringstream	ss(allNumbers);
	std::string 		token;
	
	while (ss >> token)
	{
		if (!isNumber(token))
			throw std::runtime_error("Error");
		
		long temp = std::atol(token.c_str());
		if (temp < 0 || temp > std::numeric_limits<int>::max())
			throw std::runtime_error("Error");
		vectorContainer.push_back(static_cast<int>(temp));
	}
}