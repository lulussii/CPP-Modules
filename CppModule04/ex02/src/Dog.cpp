/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:38:00 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/22 12:11:52 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog default destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Bark bark!" << std::endl;
}

