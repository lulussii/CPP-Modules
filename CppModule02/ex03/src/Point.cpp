/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:27:31 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/17 09:19:12 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& src) : x(src.x), y(src.y) {}

Point::~Point() {}

const Fixed& Point::getX() const
{
	return (this->x);
}

const Fixed& Point::getY() const
{
	return (this->y);
}

Point& Point::operator=(const Point other)
{
	(void)other;
	return *this;
}