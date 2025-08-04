/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:06:02 by lserodon          #+#    #+#             */
/*   Updated: 2025/08/04 16:47:24 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal 
{
	protected :
		std::string type;
		
	public :
		Animal();
		Animal(const Animal& other);

		virtual ~Animal();

		Animal& 		operator=(const Animal& other);
		virtual void	makeSound() const = 0;
		std::string 	getType() const;
};

#endif