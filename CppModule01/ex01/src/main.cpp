/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:20:03 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/25 12:18:36 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int n;
	int	i;
	Zombie *horde;

	n = 5;
	i = 0;
	horde = zombieHorde(n, "Zombie");
	while (i < n)
	{
		horde[i].announce();
		i++;
	}
	delete []horde;
}