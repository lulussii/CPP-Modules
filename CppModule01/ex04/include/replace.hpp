/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:00:06 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/02 11:02:09 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void		replace(std::string _file, std::string s1, std::string s2);
std::string replaceInLine(std::string line, std::string s1, std::string s2);

#endif

