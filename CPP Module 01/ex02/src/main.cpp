/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:55:20 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/01 14:25:09 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory adress of the string:\t\t" << &str << std::endl;
	std::cout << "Memory adress held by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory adress held by stringREF:\t" << &stringREF << std::endl;
	std::cout << "-------------------------------\n";
	std::cout << "Value of the string:\t\t" << str << std::endl;
	std::cout << "Value pointed by stringPTR:\t"<< *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF:\t" << stringREF << std::endl;
} 