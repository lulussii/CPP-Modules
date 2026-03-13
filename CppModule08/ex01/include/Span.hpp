/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 08:56:02 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/13 13:40:17 by lserodon         ###   ########.fr       */
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
	void	addRangeofNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	unsigned int	shortestSpan();
	unsigned int	longestSpan();
};

#endif