/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:13:33 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/17 09:45:08 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	
	public:

		Point();
		Point(const float x, const float y);
		Point(const Point& src);
		~Point();
		const Fixed& getX() const;
		const Fixed& getY() const;

		Point& operator=(const Point other);
};

Fixed	sign(Point a, Point b, Point c);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif