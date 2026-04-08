/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 08:56:02 by lserodon          #+#    #+#             */
/*   Updated: 2026/04/08 20:07:00 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
	private :

	std::vector<int>	_storage;
	unsigned int		_n;

	public :

	Span();
	Span(unsigned int N);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	void	addNumber(int number);

	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	template <typename It>
	void	addRangeofNumbers(It begin, It end)
	{
		unsigned int distance = std::distance(begin, end);

			if (_storage.size() + distance > _n)
				throw std::out_of_range ("Error: Storage capacity exceeded");
		_storage.insert(_storage.end(), begin, end);
	}
};

#endif