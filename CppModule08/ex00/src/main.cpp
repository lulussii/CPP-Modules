/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 08:55:53 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/13 09:52:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main(void)
{
	std::cout << "---- test with std::vector ----" << std::endl;
	int arr[] = {1,2,3,4,5};
	std::vector<int> v(arr, arr + sizeof(arr)/ sizeof(int));

	try {
		std::vector<int>::iterator it = easyfind(v, 4);
		std::cout << "Found:" << *it << "!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n ---- test with std::list ----" << std::endl;
	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	try {
		std::list<int>::iterator it = easyfind(l, 20);
		std::cout << "Found: " << *it << "!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n ---- test failure ----" << std::endl;
	try {
		easyfind(v, 999);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return (0);
}