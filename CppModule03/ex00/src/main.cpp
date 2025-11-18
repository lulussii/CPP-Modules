/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/17 10:48:13 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main()
{
	std::cout << "\n===== CONSTUCTION =====" << std::endl;
	
	ClapTrap a;
	ClapTrap b("Cody");
	ClapTrap c(b);
	ClapTrap d = a;

	std::cout << "\n===== ATTACK_TESTS =====" << std::endl;

	b.attack("Target1");
	b.attack("Target2");
	
	std::cout << "\n===== DAMAGE TESTS =====" << std::endl;

	b.takeDamage(3);
    b.takeDamage(20);
    b.takeDamage(2);

    std::cout << "\n===== REPAIR TESTS =====\n" << std::endl;

    a.beRepaired(3);
    a.attack("Target");
    a.beRepaired(5);

    std::cout << "\n===== ENERGY DEPLETION =====\n" << std::endl;

    ClapTrap e("Eddie");

    for (int i = 0; i < 12; i++)
        e.attack("Wall");

    std::cout << "\n===== REPAIR WHILE KO =====\n" << std::endl;

    ClapTrap f("Ghost");
    f.takeDamage(10);
    f.beRepaired(5);

    std::cout << "\n===== END OF MAIN =====\n" << std::endl;

    return 0;
}
