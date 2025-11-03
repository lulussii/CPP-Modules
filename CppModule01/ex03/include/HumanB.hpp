/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:32:34 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/03 15:24:55 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private :
		std::string _name;
		Weapon		*_weapon;

	public:
		HumanB(std::string name);
		
		void		setWeapon(Weapon &weapon);
		void		attack(void) const;
};

#endif