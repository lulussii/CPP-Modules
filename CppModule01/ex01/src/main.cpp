/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:20:03 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/03 15:21:57 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int n;
	Zombie *horde;

	n = 5;
	horde = zombieHorde(n, "Zombie");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete []horde;
}