/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:56:04 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/25 15:14:12 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

#define PINK     	"\033[38;5;205m"
#define HOT_PINK 	"\033[38;5;198m"
#define PALE_PINK   "\033[38;5;224m"
#define SOFT_PINK   "\033[38;5;218m"
#define RESET    	"\033[0m"


class PhoneBook {
	private:
		Contact _contacts[8];
		int		_count;

	public:
		PhoneBook();
		
		~PhoneBook();
		
		void	addNewContact();
		void	displayContact();
		void	searchContact();
		void	searchCommand();
};



#endif