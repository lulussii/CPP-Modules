/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:52:41 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/09 16:52:05 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(false), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

const std::string& AForm::getName() const
{
	return (this->_name);
}

int	AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade() const
{
	return (this->_execGrade);
}

bool	AForm::getisSignedbool() const
{
	return (this->_isSigned);
}

std::string	AForm::getisSigned() const
{
	if (this->_isSigned)
		return ("true");
	else
		return ("false");
}

void	AForm::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	if (!_isSigned)
	{
		this->_isSigned = true;
		std::cout << "AForm is signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << "AForm is already signed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const AForm &a)
{
	out << "AForm " << a.getName() << std::endl
		<< "sign grade : " << a.getSignGrade() << std::endl
		<< "exec grade : " << a.getExecGrade() << std::endl
		<< "is signed : " << a.getisSigned() << std::endl;
	return (out);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade is too low !");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("grade is too high !");
}

const char *AForm::IsNotSignedException::what(void) const throw()
{
	return ("it is not signed !");
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (!_isSigned)
		throw IsNotSignedException();
	if (_execGrade < executor.getGrade())
		throw GradeTooLowException();
	doAction();
}