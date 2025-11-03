/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:41:17 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/03 15:28:29 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "The program needs 3 args\n";
		return (1);
	}
	else
		ft_replace(argv[1], argv[2], argv[3]);
	return (0);
}