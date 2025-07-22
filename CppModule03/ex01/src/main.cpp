/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 13:44:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/21 08:37:47 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void)
{
	ScavTrap a("A");
	ScavTrap b(a);
	ScavTrap c = b;
	
	a.attack("enemy");
	b.attack("enemy");

	a.guardGate();
	ClapTrap *d = new ScavTrap("PointerBot");
	d->attack("a");
	delete d;

    return 0;
}