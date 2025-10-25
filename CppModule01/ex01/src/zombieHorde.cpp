/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:15:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/10/25 12:48:39 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*horde;

	i = 0;
	if (N < 1)
	{
		std::cout << "A horde need at least 2 zombies\n";
		return (NULL);
	}
	horde = new Zombie[N];
	if (!horde)
		std::cout << "Allocation of the horde failed.\n";
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}