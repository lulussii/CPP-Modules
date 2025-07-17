/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:00:14 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/02 11:02:02 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replaceInLine(std::string line, std::string s1, std::string s2)
{
	std::string result;
	size_t i;
	
	i = 0;
	while(i < line.size())
	{
		if (line.substr(i, s1.size()) == s1)
		{
			result += s2;
			i += s1.size();
		}
		else
		{
			result += line[i];
			i++;
		}
	}
	return (result);
}

void	replace(std::string _file, std::string s1, std::string s2)
{
	std::ifstream file(_file.c_str());
	std::string newFileName = _file + ".replace";

	if (!file)
	{
		std::cerr << "The file doesn't exist" << std::endl;
		exit(1);
	}
	std::ofstream newFile(newFileName.c_str());
	if (!newFile)
	{
		std::cerr << "An error occured" << std::endl;
		exit (1);
	}
	std::string line;
	std::string result;
	while (std::getline(file, line))
	{
		result = replaceInLine(line, s1, s2);
		newFile << result << std::endl;
	}
}
