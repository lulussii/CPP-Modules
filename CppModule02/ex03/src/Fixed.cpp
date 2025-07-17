/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:12:59 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/16 09:54:20 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
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

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}
		
bool	Fixed::operator>=(const Fixed& fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}
		
bool	Fixed::operator==(const Fixed& fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed Fixed::operator+(const Fixed& fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
	if (fixed.toFloat() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++()
{
	this->_rawBits++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;

	++this->_rawBits;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;

	--this->_rawBits;
	return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}