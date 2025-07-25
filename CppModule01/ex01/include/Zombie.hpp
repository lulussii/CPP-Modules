/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:16:41 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/25 15:15:32 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <sstream>

class Zombie {
	private :
		std::string _name;

	public :
		Zombie();
		
		~Zombie();
		
		void		announce();
		void		setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif