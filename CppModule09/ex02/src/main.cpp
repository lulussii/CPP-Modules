/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:06:31 by lserodon          #+#    #+#             */
/*   Updated: 2026/05/20 14:05:21 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int argc, char **argv)
{
	PmergeMe mergeMe;

	if (argc < 2)
	{
		std::cerr << "The program needs at least 2 numbers" << std::endl;
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
		std::cerr << e.what() << std::endl;
	}
	return (0);
}