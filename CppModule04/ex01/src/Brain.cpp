/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:31:31 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/22 11:51:59 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = other._ideas[i];
	return (*this);
}

const std::string &Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->_ideas[index]);
	return (this->_ideas[0]);
}

void	Brain::setIdea(std::string idea, int index)
{
	if (index >= 0 && index < 100)
		this->_ideas[index] = idea;
}