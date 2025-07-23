/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:06:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/22 10:00:31 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongCat.hpp"

int main()
{
	const WrongAnimal* meta = new WrongAnimal();
	//const WrongAnimal* j = new Dog();
	const WrongAnimal* i = new WrongCat();
	//std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	//j->makeSound();
	meta->makeSound();

	return 0;
}