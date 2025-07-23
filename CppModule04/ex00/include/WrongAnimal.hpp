/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:06:02 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/22 10:04:11 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal 
{
	protected :
		std::string type;
		
	public :
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);

		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& other);
		void	makeSound() const;
		std::string getType() const;
};

#endif