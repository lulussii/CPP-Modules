/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:25:18 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/25 11:32:26 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

std::string	Contact::askForField(const std::string& fieldName)
{
	std::string input;

	while (input.empty())
	{
		std::cout << "Enter " << fieldName << ": ";
		std::getline(std::cin, input);
		if (input.empty())	
			std::cout << HOT_PINK << fieldName << " seems empty, please retry: \n" << RESET;
	}
	return (input);
}

void	Contact::askInfo()
{
	_firstName = askForField("first name");
	_lastName = askForField("last name");
	_nickName = askForField("nick name");
	_phoneNumber = askForField("phone number");
	_darkestSecret = askForField("darkest secret");
}

std::string Contact::truncateField(const std::string& str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}

void Contact::displayContactSummary(int index) const {
	std::cout << "║"
	          << std::setw(10) << index + 1 << "│"
	          << std::setw(10) << truncateField(_firstName) << "│"
	          << std::setw(10) << truncateField(_lastName) << "│"
	          << std::setw(10) << truncateField(_nickName) << "║\n";
}

void	Contact::displayContactDetails() const {
	std::cout << "First Name: " << _firstName << "\n";
	std::cout << "Last Name: " << _lastName << "\n";
	std::cout << "Nickname: " << _nickName << "\n";
	std::cout << "Phone Number: " << _phoneNumber << "\n";
	std::cout << "Darkest Secret: " << _darkestSecret << "\n";
}