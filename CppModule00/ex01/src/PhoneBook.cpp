/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:10:48 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/15 09:54:46 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

void	PhoneBook::addNewContact()
{
	std::string force_contact;
	int			maxContacts;
	int			i;
	
	i = 0;
	maxContacts = 8;
	if (count >= maxContacts)
	{
		std::cout << HOT_PINK << "Your phonebook is full.\n" << RESET;
		std::cout << "Adding a new contact will overwrite the oldest one.\n";
		std::cout << "Do you want to continue? (y/n)\n";
		getline(std::cin, force_contact);
		if (force_contact != "y" && force_contact != "Y")
		{
			std::cout << HOT_PINK << "Contact not added.\n" << RESET;
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
	std::cout << HOT_PINK <<"New contact succesfully added at slot #" << i + 1 << "!\n" << RESET;
}

void	PhoneBook::searchContact()
{
	std::string input;

	while (true)
	{
		std::cout << SOFT_PINK << "Enter an index:" << RESET;
		getline(std::cin, input);
		if ((input.size()) != 1 || (input[0] <= '0' || input[0] > (count + '0')))
			std::cout << HOT_PINK << "Wrong index. Please retry\n" << RESET; 
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
	std::cout << "╔═══════════════════════════════════════════╗\n";
	std::cout << "║  Index   |First Name| Last Name| Nickname ║\n";
	std::cout << "║----------|----------|----------|----------║\n";
	while(i < count)
	{
		contacts[i].displayContactSummary(i);
		i++;		
	}
	std::cout << "╚═══════════════════════════════════════════╝\n\n";
	searchContact();
}

void	PhoneBook::searchCommand()
{
	if (count == 0)
			std::cout << HOT_PINK <<"Your phonebook is empty ! Add a new contact with the command ADD.\n" << RESET;
	else
		displayContact();
}

int	main(void)
{
	std::string entry;
	PhoneBook phoneBook;

	welcomeMessage();
	while (true)
	{
		std::cout << SOFT_PINK << "Enter a command > " << RESET;
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
			std::cout << HOT_PINK << "Wrong entry. Please retry\n" << RESET;
	}
}