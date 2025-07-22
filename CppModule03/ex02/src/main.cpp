/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/21 14:51:37 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main()
{
    std::cout << "--- ClapTrap test ---" << std::endl;
    ClapTrap a("Clappy");
    a.attack("a balloon");
    a.takeDamage(5);
    a.beRepaired(3);
    std::cout << std::endl;

    std::cout << "--- ScavTrap test ---" << std::endl;
    ScavTrap b("Scavvy");
    b.attack("a door");
    b.guardGate();
    std::cout << std::endl;

    std::cout << "--- FragTrap test ---" << std::endl;
    FragTrap c("Fraggy");
    c.attack("a wall");
    c.highFivesGuys();
    std::cout << std::endl;

    return 0;
}
