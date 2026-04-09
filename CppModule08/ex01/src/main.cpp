/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 08:55:53 by lserodon          #+#    #+#             */
/*   Updated: 2026/04/09 13:10:44 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>

int main(void)
{
	std::cout << "---- TEST 1 : Subject basic test ----" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n---- TEST 2 : Adding to a full span ----" << std::endl;
	try {
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;	
	}

	std::cout << "\n---- TEST 3 : Adding 15,000 numbers at once ----" << std::endl;
	try {
		Span sp(15000);
		std::vector<int> bigData;

		std::srand(std::time(0));
		for (int i = 0; i < 15000; ++i)
			bigData.push_back(std::rand());

		sp.addRangeofNumbers(bigData.begin(), bigData.end());

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error during big data test" << e.what() << std::endl;
	}
}