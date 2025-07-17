/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:15:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/01 14:49:00 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int		i;
	Zombie	*horde;

	i = 0;
	if (N < 1)
	{
		std::cout << "A horde need at least 2 zombies\n";
	}
	horde = new Zombie[N];
	if (!horde)
		std::cout << "Allocation of the horde failed.\n";
	while (i < N)
	{
		std::stringstream ss;
		ss << name << "#" << i + 1;
		horde[i].setName(ss.str());
		i++;
	}
	return (horde);
}