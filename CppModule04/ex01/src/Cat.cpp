/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:38:00 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/22 15:18:49 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat default destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
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

void	Cat::makeSound() const
{
	std::cout << "Meow meow!" << std::endl;
}

void	Cat::setIdea(std::string idea, int index)
{
	this->_brain->setIdea(idea, index);
}

std::string Cat::getIdea(int index) const
{
	return (this->_brain->getIdea(index));
}
