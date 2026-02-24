/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:35:48 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/13 09:37:05 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool		     	_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);
		
		const std::string&	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		std::string			getisSigned() const;
		bool				getisSignedbool() const;
	
		void	beSigned(Bureaucrat &signer);
		
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const Form &a);

#endif