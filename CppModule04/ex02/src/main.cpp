/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:06:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/22 16:11:58 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Brain.hpp"
#include <iostream>

int main()
{
	std::cout << "----- CREATION D'ANIMAUX -----" << std::endl;
	const Animal* j = new Animal();
	const Animal* i = new Cat();

	std::cout << "\n----- TEST DES SONS -----" << std::endl;
	j->makeSound(); // Bark
	i->makeSound(); // Meow

	std::cout << "\n----- SUPPRESSION D'ANIMAUX -----" << std::endl;
	delete j;
	delete i;

	std::cout << "\n----- TEST DE COPIE PROFONDE -----" << std::endl;
	Cat original;
	original.setIdea("Chasser la souris", 0);
	original.setIdea("Dormir au soleil", 1);

	std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;

	Cat copy = original;
	std::cout << "Copy idea[0]: " << copy.getIdea(0) << std::endl;

	// Modifier la copie
	copy.setIdea("Manger des croquettes", 0);

	std::cout << "After modification:" << std::endl;
	std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
	std::cout << "Copy idea[0]: " << copy.getIdea(0) << std::endl;

	std::cout << "\n----- TABLEAU D'ANIMAUX -----" << std::endl;
	Animal* animals[4];
	for (int n = 0; n < 2; ++n)
		animals[n] = new Dog();
	for (int k = 2; k < 4; ++k)
		animals[k] = new Cat();

	for (int l = 0; l < 4; ++l)
		animals[l]->makeSound();

	for (int m = 0; m < 4; ++m)
		delete animals[m];

	return 0;
}
