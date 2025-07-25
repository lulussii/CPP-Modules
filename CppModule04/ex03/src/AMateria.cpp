/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:52:22 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/24 08:54:47 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"

AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << "Abstract materia constructor with name called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	std::cout << "Abstract materia copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Abstract materia default destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string const& AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Abstract materia used on " << target.getName() << "." << std::endl;
}
