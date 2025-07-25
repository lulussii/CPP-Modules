/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:04:26 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/24 09:07:00 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Materia source default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; ++i)
		this->_inventory[i] = (other._inventory[i])->clone();
	std::cout << "Materia source copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
		for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i])
			delete(this->_inventory[i]);
	}
	std::cout << "Materia source default destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
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

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materia && !this->_inventory[i])
		{
			this->_inventory[i] = materia;
			return ;
		}
	}
	std::cout << "Inventory is full." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	std::cout << "Cannot create materia, " << type << " is invalid ! " << std::endl;
	return (0);
}