/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:06:31 by lserodon          #+#    #+#             */
/*   Updated: 2026/04/23 16:44:33 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	PmergeMe mergeMe;

	if (argc <= 2)
	{
		std::cout << "The program needs at least 2 numbers" << std::endl;
		return (1);
	}
	try 
	{
		mergeMe.parseNumbers(argc, argv);
		mergeMe.printBefore();
		mergeMe.vectorAlgo();
		mergeMe.dequeAlgo();		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}