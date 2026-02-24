/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:35:48 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/13 10:02:35 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool		     	_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other);
		
		const std::string&	getName() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		std::string			getisSigned() const;
		bool				getisSignedbool() const;
	
		void 			execute(Bureaucrat const & executor) const;
		virtual void	doAction() const = 0;

		void	beSigned(Bureaucrat &signer);
		
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
		class IsNotSignedException : public std::exception {
			const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &a);

#endif