/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/31 11:27:31 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void)
{
	std::cout << "----- CONSTRUCTION ------" << std::endl;
	
	ScavTrap a;
	ScavTrap b("Cody");

	std::cout << "\n----- TESTING -----" << std::endl;
	
	a.attack("some other robot");
	a.attack("some other other robot");
	a.takeDamage(10);
	b.beRepaired(10);
	for (int i = 0; i < 4; i++)
		b.attack("Cody-clone");
	b.guardGate();
	
	std::cout << "\n----- DECONSTRUCTION -----" << std::endl;
	
	return (0);
}