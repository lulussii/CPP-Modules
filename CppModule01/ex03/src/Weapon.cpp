/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:31:42 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/25 12:27:50 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	return ;
}

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const &Weapon::getType(void) const
{
	return (this->_type);
}