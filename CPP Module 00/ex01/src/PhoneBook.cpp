/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:10:48 by lserodon          #+#    #+#             */
/*   Updated: 2025/06/25 13:48:30 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addNewContact()
{
	std::string force_contact;
	int			maxContacts;
	int			i;
	
	i = 0;
	maxContacts = 8;
	if (count >= maxContacts)
	{
		std::cout << "Your phonebook is full.\n";
		std::cout << "Adding a new contact will overwrite the oldest one.\n";
		std::cout << "Do you want to continue? (y/n)\n";
		getline(std::cin, force_contact);
		if (force_contact != "y" && force_contact != "Y")
		{
			std::cout << "Contact not added.\n";
			return ;		
		}
		i = count % maxContacts;
	}
	else
	{
		i = count;		
		count++;
	}
	contacts[i].askInfo();
	std::cout << "New contact succesfully added at slot #" << i + 1 << "!\n";
}

void	PhoneBook::searchContact()
{
	std::string input;

	while (true)
	{
		std::cout << "Enter an index:";
		getline(std::cin, input);
		if ((input.size()) != 1 || (input[0] <= '0' || input[0] > (count + '0')))
			std::cout << "Wrong index. Please retry\n"; 
		else
		{
			contacts[(input[0] - '0') - 1].displayContactDetails();
			break;
		}
	}
}

void	PhoneBook::displayContact()
{
	int i;

	i = 0;
	std::cout << "|-------------------------------------------|\n";
	std::cout << "|  Index   |First Name| Last Name| Nickname |\n";
	std::cout << "|----------|----------|----------|----------|\n";
	while(i < count)
	{
		contacts[i].displayContactSummary(i);
		i++;		
	}
	std::cout << "|-------------------------------------------|\n\n";
	searchContact();
}

void	PhoneBook::searchCommand()
{
	if (count == 0)
			std::cout << "Your phonebook is empty ! Add a new contact with the command ADD.\n";
	else
		displayContact();
}

int	main(void)
{
	std::string entry;
	PhoneBook phoneBook;

	while (true)
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, entry);
		if (entry == "EXIT")
		{
			std::cout << "Goodbye !\n";
			break;
		}
		else if (entry == "ADD")
		{
			phoneBook.addNewContact();
		}
		else if (entry == "SEARCH")
		{
			phoneBook.searchCommand();
		}
		else
			std::cout << "Wrong entry. Please retry\n";
	}
}