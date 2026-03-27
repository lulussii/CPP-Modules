/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:32:35 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/18 13:53:15 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/iter.hpp"

template <typename T>
void print(T const& x)
{
	std::cout << x << " ";
}

void	increment(int &n)
{
	n += 1;
}

int main(void) 
{
	std::cout << "---- Test 1 : Array of int ---" << std::endl;
	int intArray[] = {1,2,3,4,5};
	size_t intLen = 5;
	
	std::cout << "Before : ";
	iter(intArray, intLen, print<int>);
	
	iter(intArray, intLen, increment);

	std::cout << std::endl << "After : ";
	iter(intArray, intLen, print<int>);
	std::cout << std::endl << std::endl;

	std::cout << "---- Test 2 : Array of std::string ---- " << std::endl;
	std::string strArray[] = {"coucou", "les", "copains"};
	size_t strLen = 3;

	iter(strArray, strLen, print<std::string>);
	std::cout << std::endl << std::endl;

	std::cout << "---- Test 3 : Const array ----" << std::endl;

	const int constArray[] = {42, 21, 84};
	size_t constLen = 3;

	iter(constArray, constLen, print<int>);
	
	return 0;
}