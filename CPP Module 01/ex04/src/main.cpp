/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 08:41:17 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/02 11:00:58 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "The program needs 3 args\n";
	else
		replace(argv[1], argv[2], argv[3]);
	return (0);
}