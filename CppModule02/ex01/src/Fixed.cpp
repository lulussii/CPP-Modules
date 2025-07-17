/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:12:59 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/16 09:50:15 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	this->_rawBits = 0;
}

Fixed::Fixed(const int value)
{
	this->_rawBits = value << 8;
}

Fixed::Fixed(const float value)
{
	this->_rawBits = roundf(value * 256);
}

Fixed::~Fixed(void)
{
	return ;
}

Fixed::Fixed(const Fixed& src)
{
	this->_rawBits = src.getRawBits();
}
Fixed& Fixed::operator=(const Fixed& src)
{
	if (this != &src)
		this->_rawBits = src.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_rawBits / 256);
}

int	Fixed::toInt(void) const
{
	return (this->_rawBits >> 8);
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	return (out << value.toFloat());	
}