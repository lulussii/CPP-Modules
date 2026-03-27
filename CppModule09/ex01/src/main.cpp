/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:36:05 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/26 15:39:24 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN rpn;
	
	if (argc != 2)
		std::cout << "Error: The program needs a RPN expression in argument" << std::endl;
	else
		rpn.parseOperation(argv[1]);
}