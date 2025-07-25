/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:10:48 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/25 09:35:00 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0)
{
	std::cout << PINK << std::endl;
	std::cout << "╔══════════════════════════════════════════════╗" << std::endl;
	std::cout << "║        💖 WELCOME TO YOUR PHONEBOOK 💖       ║" << std::endl;
	std::cout << "╠══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ AVAILABLE COMMANDS:                          ║" << std::endl;
	std::cout << "║   ADD    → Add a new contact                 ║" << std::endl;
	std::cout << "║   SEARCH → Search & display your contacts    ║" << std::endl;
	std::cout << "║   EXIT   → Exit the program                  ║" << std::endl;
	std::cout << "╚══════════════════════════════════════════════╝" << std::endl;
	std::cout << RESET << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << PINK << std::endl;
	std::cout << "╔══════════════════════════════════════════════╗" << std::endl;
	std::cout << "║        💖         GOODBYE !         💖       ║" << std::endl;
	std::cout << "╚══════════════════════════════════════════════╝" << std::endl;
	std::cout << RESET << std::endl;
}

void	PhoneBook::addNewContact()
{
	std::string force_contact;
	int			maxContacts;
	int			i;
	
	i = 0;
	maxContacts = 8;
	if (_count >= maxContacts)
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
		i = _count % maxContacts;
	}
	else
	{
		i = _count;		
		_count++;
	}
	_contacts[i].askInfo();
	std::cout << HOT_PINK <<"New contact succesfully added at slot #" << i + 1 << "!\n" << RESET;
}

void	PhoneBook::searchContact()
{
	std::string input;

	while (true)
	{
		std::cout << SOFT_PINK << "Enter an index:" << RESET;
		getline(std::cin, input);
		if ((input.size()) != 1 || (input[0] <= '0' || input[0] > (_count + '0')))
			std::cout << HOT_PINK << "Wrong index. Please retry\n" << RESET; 
		else
		{
			_contacts[(input[0] - '0') - 1].displayContactDetails();
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
	while(i < _count)
	{
		_contacts[i].displayContactSummary(i);
		i++;		
	}
	std::cout << "╚═══════════════════════════════════════════╝\n\n";
	searchContact();
}

void	PhoneBook::searchCommand()
{
	if (_count == 0)
			std::cout << HOT_PINK <<"Your phonebook is empty ! Add a new contact with the command ADD.\n" << RESET;
	else
		displayContact();
}

int	main(void)
{
	std::string entry;
	PhoneBook phoneBook;

	while (true)
	{
		std::cout << SOFT_PINK << "Enter a command > " << RESET;
		std::getline(std::cin, entry);
		if (entry == "EXIT")
		{
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