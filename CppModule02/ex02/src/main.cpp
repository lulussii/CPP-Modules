/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:29:26 by lserodon          #+#    #+#             */
/*   Updated: 2025/11/11 10:06:31 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);

	std::cout << "\n=== DISPLAY VALUES ===" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "\n=== COMPARISON OPERATORS ===" << std::endl;
	std::cout << "a > b:  " << (a > b) << std::endl;
	std::cout << "a < b:  " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << "\n=== ARITHMETIC OPERATORS ===" << std::endl;
	Fixed e = b + c;
	Fixed f = c - b;
	Fixed g = b * c;
	Fixed h = c / b;

	std::cout << "b + c = " << e << std::endl;
	std::cout << "c - b = " << f << std::endl;
	std::cout << "b * c = " << g << std::endl;
	std::cout << "c / b = " << h << std::endl;

	std::cout << "\n=== INCREMENT / DECREMENT ===" << std::endl;
	Fixed i;
	std::cout << "i   = " << i << std::endl;
	std::cout << "++i = " << ++i << std::endl;
	std::cout << "i   = " << i << std::endl;
	std::cout << "i++ = " << i++ << std::endl;
	std::cout << "i   = " << i << std::endl;
	std::cout << "--i = " << --i << std::endl;
	std::cout << "i   = " << i << std::endl;
	std::cout << "i-- = " << i-- << std::endl;
	std::cout << "i   = " << i << std::endl;

	std::cout << "\n=== MIN / MAX FUNCTIONS ===" << std::endl;
	Fixed x(10.1f);
	Fixed y(20.2f);

	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
	std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;

	const Fixed cx(100.5f);
	const Fixed cy(50.25f);
	std::cout << "const min(cx, cy) = " << Fixed::min(cx, cy) << std::endl;
	std::cout << "const max(cx, cy) = " << Fixed::max(cx, cy) << std::endl;

	std::cout << "\n=== DIVISION BY ZERO TEST ===" << std::endl;
	Fixed zero(0);
	Fixed result = c / zero;
	std::cout << "c / 0 = " << result << std::endl;

	return 0;
}
