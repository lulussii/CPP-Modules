/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:11:11 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/13 10:19:14 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("Defualt target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

void ShrubberyCreationForm::doAction() const
{
	std::ofstream outfile((_target + "_shrubbery").c_str());

	if (outfile)
	{
		outfile <<
		"       ccee88oo\n"
		"   C8O8O8Q8PoOb o8oo\n"
		"  dOB69QO8PdUOpugoO9bD\n"
		" CgggbU8OU qOp qOdoUOdcb\n"
		"    6OuU  /p u gcoUodpP\n"
		"      \\\\//  /douUP\n"
		"        \\\\////\n"
		"         |||\n"
		"         |||\n"
		"         |||\n"
		"   .....//||||\\....\n";
	}
	else
		throw OpenFileException();
}

const char *ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return ("Failed to open file");
}