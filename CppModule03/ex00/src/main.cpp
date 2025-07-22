/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/21 08:31:11 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("A");                       
    ClapTrap b("B");            
    ClapTrap c = b;                     

    a.attack("enemy");
    b.attack("enemy");
    c.attack("enemy");

    a.takeDamage(5);
    b.takeDamage(15);

    a.beRepaired(3);
    b.beRepaired(10);

    ClapTrap d;
    d = b;
    d.attack("another enemy");

    b.takeDamage(100);                 
    b.attack("enemy");
    b.beRepaired(5);

    return 0;
}