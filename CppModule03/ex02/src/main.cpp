/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/17 16:26:41 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "\n===== CREATION =====\n" << std::endl;

    FragTrap f1("Fraggy");
    FragTrap f2(f1);
    FragTrap f3;
    f3 = f1;
    
    std::cout << "\n===== ATTACK TEST =====\n" << std::endl;

    f1.attack("Target1");
    f1.attack("Target2");

    std::cout << "\n===== SPECIAL ABILITY =====\n" << std::endl;

    f1.highFivesGuys();

    std::cout << "\n===== DAMAGE & REPAIRS =====\n" << std::endl;

    f1.takeDamage(20);
    f1.beRepaired(10);
    f1.takeDamage(50);
    f1.beRepaired(20);

    std::cout << "\n===== DEATH TEST =====\n" << std::endl;

    f1.takeDamage(200);

    f1.attack("Target3");
    f1.beRepaired(10);
    f1.highFivesGuys();

    std::cout << "\n===== END OF MAIN =====\n" << std::endl;

    return 0;
}

