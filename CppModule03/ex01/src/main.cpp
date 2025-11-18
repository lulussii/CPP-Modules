/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/17 11:50:30 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void)
{
	std::cout << "\n===== CONSTUCTION =====" << std::endl;
	
	ScavTrap a;
	ScavTrap b("Cody");
	ScavTrap c(b);
	ScavTrap d = a;

	std::cout << "\n===== ATTACK_TESTS =====" << std::endl;

	b.attack("Target1");
	b.attack("Target2");
	
	std::cout << "\n===== SPECIAL MODE =====" << std::endl;

	b.guardGate();
	
    std::cout << "\n===== DAMAGE & DEATH =====\n" << std::endl;

    a.takeDamage(30);
    a.takeDamage(50);
    a.takeDamage(40);

    a.attack("Target while dead");
    a.guardGate();

    std::cout << "\n===== ENERGY DEPLETION =====\n" << std::endl;

    ScavTrap e("NoEnergy");

    for (int i = 0; i < 51; i++)
        e.attack("wall");

    e.guardGate();

    std::cout << "\n===== END OF MAIN =====\n" << std::endl;

    return 0;
}