/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:27:31 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/30 14:29:13 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& src) : _x(src._x), _y(src._y) {}

Point::~Point() {}

const Fixed& Point::getX() const
{
	return (this->_x);
}

const Fixed& Point::getY() const
{
	return (this->_y);
}

Point& Point::operator=(const Point other)
{
	(void)other;
	return *this;
}