/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:32:36 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/01 16:08:37 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <cstring>
#include "Weapon.hpp"

class HumanA 
{
	private :
		std::string _name;
		Weapon	 	&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		void attack(void) const;
};

#endif