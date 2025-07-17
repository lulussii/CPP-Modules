/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:25:18 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/15 09:54:37 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBookUtils.hpp"

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
	firstName = askForField("first name");
	lastName = askForField("last name");
	nickName = askForField("nick name");
	phoneNumber = askForField("phone number");
	darkestSecret = askForField("darkest secret");
}

std::string Contact::truncateField(const std::string& str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return std::string(10 - str.length(), ' ') + str;
}

void	Contact::displayContactSummary(int index) const {
	std::cout << "║" << std::string(9, ' ') << index + 1
			  << "|" << truncateField(firstName)
			  << "|" << truncateField(lastName)
			  << "|" << truncateField(nickName) << "║\n";
}

void	Contact::displayContactDetails() const {
	std::cout << "First Name: " << firstName << "\n";
	std::cout << "Last Name: " << lastName << "\n";
	std::cout << "Nickname: " << nickName << "\n";
	std::cout << "Phone Number: " << phoneNumber << "\n";
	std::cout << "Darkest Secret: " << darkestSecret << "\n";
}