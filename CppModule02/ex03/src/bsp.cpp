/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:36:59 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/17 09:49:49 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"

Fixed	sign(Point a, Point b, Point c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = sign(point, a, b);
	Fixed d2 = sign(point, b, c);
	Fixed d3 = sign(point, c, a);

	bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	
	if ((has_neg && has_pos) || (d1 == 0 || d2 == 0 || d3 == 0))
		return false;
	return true;
}