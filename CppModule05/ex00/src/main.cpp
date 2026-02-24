/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:01:09 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/13 09:22:26 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::cout << "----- TEST 1 : Valid creation -----" << std::endl;
	try {
		Bureaucrat a("Jean", 42);
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 2 : Grade too high (0) -----" << std::endl;
	try {
		Bureaucrat b("Luc", 0);
		std::cout << b << std::endl; 
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 3 : Grade too low (151) -----" << std::endl;
	try {
		Bureaucrat c("Marie", 151);
		std::cout << c << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 4 : incrementGrade OK -----" << std::endl;
	try {
		Bureaucrat d("Paul", 10);
		std::cout << d << std::endl;
		d.incrementGrade();
		std::cout << d << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 5 : incrementGrade too high -----" << std::endl;
	try {
		Bureaucrat e("Anna", 1);
		std::cout << e << std::endl;
		e.incrementGrade();
		std::cout << e << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 6 : decrementGrade OK -----" << std::endl;
	try {
		Bureaucrat f("Leo", 149);
		std::cout << f << std::endl;
		f.decrementGrade();
		std::cout << f << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n----- TEST 7 : decrementGrade too low -----" << std::endl;
	try {
		Bureaucrat g("Iris", 150);
		std::cout << g << std::endl;
		g.decrementGrade();
		std::cout << g << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
