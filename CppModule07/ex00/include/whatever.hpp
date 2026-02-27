/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:31:36 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/24 10:52:14 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &value1, T &value2)
{
	T tmp = value1;
	value1 = value2;
	value2 = tmp;
}

template <typename T>
const T& min(const T &value1, const T &value2)
{
	if (value1 < value2)
		return (value1);
	else
		return (value2);
}

template <typename T>
const T max(const T &value1, const T &value2)
{
	if (value1 > value2)
		return (value1);
	else
		return (value2);
}

#endif