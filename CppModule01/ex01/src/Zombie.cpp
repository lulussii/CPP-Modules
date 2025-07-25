/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:18:45 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/25 12:19:30 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie has joined the horde!\n";
}

Zombie::~Zombie()
{
	std::cout << _name << " has fallen...\n";
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinzzzZ...\n";
}