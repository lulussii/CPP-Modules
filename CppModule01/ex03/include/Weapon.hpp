/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:32:32 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/25 15:17:46 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <cstring>

class Weapon 
{
	private:
	std::string 		_type;
	
	public:
	Weapon();
	Weapon(std::string type);
	
	const std::string	&getType() const;
	void				setType(std::string type);
};

#endif