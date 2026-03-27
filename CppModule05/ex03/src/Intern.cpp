/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:53:57 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/09 17:04:03 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern &Intern::operator=(const Intern& other) 
{
	(void)other;
	return (*this);
}

AForm	*Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *form;
	
	std::string forms[]={"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*functions[])(std::string) = 
	{
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential
	};

	for (int i = 0; i < 3 ; i++)
	{
		if (forms[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			form = (this->*functions[i])(target);
			return form;
		}
	}

	std::cout << "Intern can't create a form called " << name << std::endl;
	return (NULL);
}