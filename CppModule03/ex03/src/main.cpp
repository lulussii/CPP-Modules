/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/21 16:41:30 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include "../include/DiamondTrap.hpp"

int main() {
    DiamondTrap dt1("Lucie");
    dt1.attack("le méchant ennemi");
    dt1.whoAmI();

    std::cout << "\n--- Copie et assignation ---" << std::endl;
    DiamondTrap dt2(dt1);       // test du constructeur de copie
    dt2.whoAmI();

    DiamondTrap dt3;
    dt3 = dt1;                  // test de l'opérateur d'assignation
    dt3.whoAmI();

    return 0;
}
