/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:31:36 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/24 12:31:50 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename Func>
void	iter(T *array, const size_t length, Func func)
{
	if (!array)
		return;

	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif