/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:56:04 by lserodon          #+#    #+#             */
/*   Updated: 2025/06/30 15:39:31 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBookUtils.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int		count;

	public:
		PhoneBook() {
			count = 0;
		}
		void addNewContact();
		void displayContact();
		void searchContact();
		void searchCommand();
};



#endif