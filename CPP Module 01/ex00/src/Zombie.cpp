/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:12:17 by lserodon          #+#    #+#             */
/*   Updated: 2025/06/30 15:29:05 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << name << " destroyed\n";
}

Zombie *newZombie(std::string name)
{
	return (new Zombie(name));
}

void randomChump(std::string name)
{
	Zombie zombieStack(name);
	zombieStack.announce();
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinzzzZ...\n";
}

int main(void)
{
	std::string heapName;
	std::string	stackName;
	
	std::cout << "Name your zombie: ";
	std:: cin >> heapName;
	Zombie *zombieHeap = newZombie(heapName);
	zombieHeap->announce();
	std::cout << "Name your zombie: ";
	std:: cin >> stackName;
	randomChump(stackName);
	delete zombieHeap;
}