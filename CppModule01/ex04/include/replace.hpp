/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:00:06 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/03 15:28:13 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

void		ft_replace(std::string _file, std::string s1, std::string s2);
std::string replaceInLine(const std::string& line, const std::string& s1,const std::string& s2);

#endif

