/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:31:29 by lserodon          #+#    #+#             */
/*   Updated: 2025/08/04 16:28:14 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;

	public :
		Dog();
		Dog(const Dog& other);

		~Dog();

		Dog& operator=(const Dog& other);
		void	makeSound() const;
		
		void		setIdea(std::string idea, int index);
		std::string	getIdea(int index) const;
};

#endif