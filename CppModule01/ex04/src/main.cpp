/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:41:17 by lserodon          #+#    #+#             */
/*   Updated: 2025/10/25 13:08:33 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "The program needs 3 args\n";
	else
		ft_replace(argv[1], argv[2], argv[3]);
	return (0);
}