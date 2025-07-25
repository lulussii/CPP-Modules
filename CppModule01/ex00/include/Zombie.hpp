/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:13:08 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/25 15:15:16 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private :
		std::string _name;

	public :
		Zombie(std::string name);
		
		~Zombie(void);
		
		void		announce();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif