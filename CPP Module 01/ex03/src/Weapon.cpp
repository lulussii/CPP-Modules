/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:31:42 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/01 16:12:31 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	return ;
}

Weapon::Weapon(std::string type) : type(type)
{
	return ;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string const &Weapon::getType(void) const
{
	return (this->type);
}