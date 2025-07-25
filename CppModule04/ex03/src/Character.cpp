/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:43:49 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/24 08:39:24 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character() : _name("Default"), _inventory()
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name), _inventory()
{
	std::cout << "Character constructor with name called" << std::endl;
}

Character::Character(const Character& other) : _name(other._name)
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = (other._inventory[i])->clone();
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_inventory[i])
			delete(_inventory[i]);
	}
	std::cout << "Default destructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	if(this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->_inventory[i])
				delete (this->_inventory[i]);
			if (other._inventory[i])
				this->_inventory[i] = (other._inventory[i])->clone();
		}
	}
	return (*this);
}

std::string const& Character::getName () const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; ++i)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << "Equiped materia in slot " << i << "." << std::endl;
			return ;
		}
	}
	std::cout << "Inventory full, cannot equiped materia." << std::endl; 
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid inventory index." << std::endl;
		return ; 
	}
	if (!this->_inventory[idx])
	{
		std::cout << "No materia to unequip in slot " << idx << "." << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
	std::cout << "Unequipped materia from slot " << idx << "." << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Invalid inventory index." << std::endl;
		return;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "No materia to use in slot " << idx << "." << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}