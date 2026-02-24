/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:01:09 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/13 09:56:09 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

int main() {
	
	std::cout << "===== FORMS SHOULD WORK =====\n" << std::endl;

	std::cout << "----- BUREAUCRATS CONSTRUCTION -----\n" << std::endl;

	Bureaucrat alice("Alice", 50);
	Bureaucrat bob("Bob", 25);
	Bureaucrat charlie("Charlie", 1);

	std::cout << alice << std::endl;
	std::cout << bob << std::endl;
	std::cout << charlie << std::endl;

	std::cout << "\n----- FORMS CONSTRUCTION -----\n" << std::endl;

	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robot("Marvin");
	PresidentialPardonForm pardon("Ford");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "----- SIGNING FORMS -----\n" << std::endl;

	try { alice.signForm(shrub); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { bob.signForm(robot); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { charlie.signForm(pardon); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "\n----- EXECUTING FORMS -----\n" << std::endl;

	try { alice.executeForm(shrub); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { bob.executeForm(robot); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { charlie.executeForm(pardon); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }


	// -------------------------------------------------------------

	std::cout << "\n===== FORMS SHOULD FAIL =====\n" << std::endl;

	std::cout << "----- BUREAUCRATS CONSTRUCTION -----\n" << std::endl;

	Bureaucrat A("Alice", 150);
	Bureaucrat B("Bob", 73);
	Bureaucrat C("Charlie", 13);

	std::cout << A << std::endl;
	std::cout << B << std::endl;
	std::cout << C << std::endl;

	std::cout << "\n----- FORMS CONSTRUCTION -----\n" << std::endl;

	ShrubberyCreationForm s("Home");
	RobotomyRequestForm r("Marvin");
	PresidentialPardonForm p("Ford");

	std::cout << s << std::endl;
	std::cout << r << std::endl;
	std::cout << p << std::endl;

	std::cout << "----- SIGNING FORMS -----\n" << std::endl;

	try { A.signForm(s); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { B.signForm(r); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { C.signForm(p); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "\n----- EXECUTING FORMS -----\n" << std::endl;

	try { A.executeForm(s); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { B.executeForm(r); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	try { C.executeForm(p); }
	catch (std::exception &e) { std::cout << e.what() << std::endl; }

	return 0;
}
