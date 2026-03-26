/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:43:15 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/17 16:59:51 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

int   parseFile(std::string _file)
{
    std::ifstream file(_file.c_str());
    if (!file)
    {
        std::cout << "Error : The file doesn't exist" << std::endl;
        return (1);
    }
    
}