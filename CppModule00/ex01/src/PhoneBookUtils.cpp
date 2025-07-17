/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:36:11 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/15 09:54:57 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBookUtils.hpp"

void	welcomeMessage()
{
	std::cout << PINK;
	std::cout << "╔══════════════════════════════════════════════╗" << std::endl;
	std::cout << "║        💖 WELCOME TO YOUR PHONEBOOK 💖       ║" << std::endl;
	std::cout << "╠══════════════════════════════════════════════╣" << std::endl;
	std::cout << "║ AVAILABLE COMMANDS:                          ║" << std::endl;
	std::cout << "║   ADD    → Add a new contact                 ║" << std::endl;
	std::cout << "║   SEARCH → Search & display your contacts    ║" << std::endl;
	std::cout << "║   EXIT   → Exit the program                  ║" << std::endl;
	std::cout << "╚══════════════════════════════════════════════╝" << std::endl;
	std::cout << RESET;
}