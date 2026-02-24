/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:45:09 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:14 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test n°" << i + 1 << " :" << std::endl;
		
		Base *Test = generate();

		std::cout << "Pointer identification   : ";
		identify(Test);

		std::cout << "Reference identification : ";
		identify(*Test);

		delete (Test);
		std::cout << "---------------------" << std::endl;
	}
}