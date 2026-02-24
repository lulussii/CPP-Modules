/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:52:41 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/13 09:51:55 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other) : _name(other._name), _isSigned(false), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

const std::string& Form::getName() const
{
	return (this->_name);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int	Form::getExecGrade() const
{
	return (this->_execGrade);
}

bool	Form::getisSignedbool() const
{
	return (this->_isSigned);
}

std::string	Form::getisSigned() const
{
	if (this->_isSigned)
		return ("true");
	else
		return ("false");
}

void	Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	if (!_isSigned)
	{
		this->_isSigned = true;
		std::cout << "Form is signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << "Form is already signed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Form &a)
{
	out << "Form " << a.getName() << std::endl
		<< "sign grade : " << a.getSignGrade() << std::endl
		<< "exec grade : " << a.getExecGrade() << std::endl
		<< "is signed : " << a.getisSigned() << std::endl;
	return (out);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("grade is too low !");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("grade is too high !");
}