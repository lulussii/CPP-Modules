/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:01:09 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/13 09:55:56 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "----- TEST 1 : Create a valid form -----\n" << std::endl;
	try {
		Form f1("TopSecret", 50, 20);
		std::cout << f1 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "----- TEST 2 : Create a form with too high grades -----\n" << std::endl;
	try {
		Form f2("ImpossibleForm", 0, 0);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 3 : Create a form with too low grades -----\n" << std::endl;
	try {
		Form f3("ImpossibleForm2", 151, 200);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 4 : Bureaucrat signs a form successfully -----\n" << std::endl;
	try {
		Bureaucrat b1("Alice", 30);
		Form f4("Confidential", 50, 20);

		b1.signForm(f4);
		std::cout << f4 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "----- TEST 5 : Bureaucrat cannot sign due to low grade -----\n" << std::endl;
	try {
		Bureaucrat b2("Bob", 100);
		Form f5("TopSecret", 50, 20);

		b2.signForm(f5);
		std::cout << f5 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "----- TEST 6 : Signing an already signed form -----\n" << std::endl;
	try {
		Bureaucrat b3("Charlie", 10);
		Form f6("StandardForm", 50, 20);

		b3.signForm(f6);
		b3.signForm(f6);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

