/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:06:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/08/04 16:44:57 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Brain.hpp"
#include <iostream>

int main() 
{
	std::cout << "----- CONSTRUCTION -----" << std::endl;
    Dog a;
		
	std::cout << "\n----- TESTING -----" << std::endl;
	
    a.setIdea("I am a", 0);

    Dog b = a;
	
    b.setIdea("I am b", 0);
	std::cout << a.getIdea(0) << std::endl;
	std::cout << b.getIdea(0) << std::endl;

	std::cout << "\n----- DESTRUCTION -----" << std::endl;
    return (0);·
}

