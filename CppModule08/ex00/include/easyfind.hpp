/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 08:56:02 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/13 09:52:46 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception
{
	const char* what() const throw() {
		return "Value not found in container";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw NotFoundException();

	return it;
}

#endif