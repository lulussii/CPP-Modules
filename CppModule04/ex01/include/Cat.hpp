/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:31:29 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/22 15:19:02 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private :
		Brain* _brain;

	public :
		Cat();
		Cat(const Cat& other);

		~Cat();

		Cat& 		operator=(const Cat& other);
		void		makeSound() const;
		
		void		setIdea(std::string idea, int index);
		std::string	getIdea(int index) const;
};

#endif