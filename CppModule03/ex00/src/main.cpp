/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/31 10:28:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main()
{
	std::cout << "----- CONSTRUCTION ------" << std::endl;
	
	ClapTrap a;
	ClapTrap b("Cody");

	std::cout << "\n----- TESTING -----" << std::endl;
	
	a.attack("some other robot");
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	for (int i = 0; i < 4; i++)
		b.attack("Cody-clone");
	b.beRepaired(3);
	
	std::cout << "\n----- DECONSTRUCTION -----" << std::endl;
	
	return (0);
}
