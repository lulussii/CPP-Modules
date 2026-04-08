/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:57:48 by lserodon          #+#    #+#             */
/*   Updated: 2026/04/08 20:17:44 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iterator>
#include <iostream>
#include <algorithm>

Span::Span() {}

Span::Span(unsigned int N) : _n(N) {}

Span::Span(const Span &other) : _storage(other._storage), _n(other._n) {}

Span::~Span() {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_n = other._n;
		this->_storage = other._storage;
	}
	return *this;
}

void	Span::addNumber(int number)
{
	if (_storage.size() >= _n)
		throw std::out_of_range ("Error: Storage capacity exceeded");
	
	_storage.push_back(number);
}

unsigned int Span::shortestSpan()
{
	if (_storage.size() <= 1)
		throw std::logic_error ("Error: Not enough elements to calculate span");

	std::sort(_storage.begin(), _storage.end());

	unsigned int min_diff = _storage[1] - _storage[0];
	
	for (size_t i = 1; i < _storage.size() - 1; i++)
	{
		unsigned int current_diff = _storage[i + 1] - _storage[i];
		if (current_diff < min_diff)
			min_diff = current_diff;
	}
	return (min_diff);
}

unsigned int Span::longestSpan()
{
	if (_storage.size() <= 1)
		throw std::logic_error ("Error: Not enough elements to calculate span");

	std::sort(_storage.begin(), _storage.end());

	return (_storage.back() - _storage.front());
}

