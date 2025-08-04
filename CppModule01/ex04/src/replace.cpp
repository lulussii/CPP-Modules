/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:00:14 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/30 12:11:01 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/replace.hpp"

std::string replaceInLine(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t found;
	
	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result += line.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += line.substr(pos);
	return (result);
}

void	ft_replace(std::string _file, std::string s1, std::string s2)
{
	std::ifstream file(_file.c_str());
	std::string newFileName = _file + ".replace";

	if (!file)
	{
		std::cerr << "The file doesn't exist" << std::endl;
		exit (1);
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
	newFile.close();
	file.close();
}
