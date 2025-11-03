/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:18:45 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/03 15:14:31 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "A zombie has joined the horde!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " has fallen..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce() const
{
	std::cout << _name << ": BraiiiiiiinzzzZ..." << std::endl;
}