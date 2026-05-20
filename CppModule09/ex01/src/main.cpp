/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:36:05 by lserodon          #+#    #+#             */
/*   Updated: 2026/05/20 14:02:08 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;
	
	if (argc != 2)
	{
		std::cerr << "Error: The program needs a RPN expression in argument" << std::endl;
		return (1);
	}
		
	try 
	{
		rpn.parseOperation(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}