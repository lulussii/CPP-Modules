/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/18 11:34:19 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main()
{
    std::cout << "\n===== DIAMONDTRAP CREATION =====\n" << std::endl;

    DiamondTrap d1("Diamond");
    DiamondTrap d2(d1);
    DiamondTrap d3;
    d3 = d1;

    std::cout << "\n===== ATTACK TEST =====\n" << std::endl;

    d1.attack("Target1");
    d1.attack("Target");

    std::cout << "\n===== SPECIAL ABILITIES =====\n" << std::endl;

    d1.highFivesGuys();
    d1.guardGate();
    d1.whoAmI();

    std::cout << "\n===== DAMAGE & REPAIRS =====\n" << std::endl;

    d1.takeDamage(40);
    d1.beRepaired(20);

    d1.takeDamage(70);

    d1.attack("After death");
    d1.beRepaired(10);
    d1.guardGate();
    d1.highFivesGuys();
    d1.whoAmI();

    std::cout << "\n===== WHO AM I =====\n" << std::endl;

    DiamondTrap d4("Diamond");

    d4.whoAmI();

    std::cout << "\n===== END OF MAIN =====\n" << std::endl;

    return 0;
}