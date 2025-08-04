/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/31 13:56:46 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main() {

	std::cout << "----- CONSTRUCTION ------" << std::endl;
	
	DiamondTrap a;
	DiamondTrap b("Cody");

	std::cout << "\n----- TESTING -----" << std::endl;
	
	a.attack("some other robot");
	a.attack("some other other robot");
	b.whoAmI();
	for (int i = 0; i < 4; i++)
		b.attack("Cody-clone");
	b.highFivesGuys();
	
	std::cout << "\n----- DECONSTRUCTION -----" << std::endl;
	
	return (0);
}
