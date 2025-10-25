/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 09:31:25 by lserodon          #+#    #+#             */
/*   Updated: 2025/10/25 12:44:23 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	
	if (argc != 2)
	{
		std::cout << "Wrong number of args\n";
		return (1);
	}
	else
		harl.complain(argv[1]);
	return (0);
}
