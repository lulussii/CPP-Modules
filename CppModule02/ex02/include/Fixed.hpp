/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:12:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/16 09:48:37 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _rawBits;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& src);
		
		~Fixed();
		
		Fixed& 	operator=(const Fixed& src);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		
		bool	operator>(const Fixed& fixed) const;
		bool	operator<(const Fixed& fixed) const;
		bool	operator>=(const Fixed& fixed) const;
		bool	operator<=(const Fixed& fixed) const;
		bool	operator==(const Fixed& fixed) const;
		bool	operator!=(const Fixed& fixed) const;
		
		Fixed	operator+(const Fixed& fixed) const;
		Fixed	operator-(const Fixed& fixed) const;
		Fixed	operator*(const Fixed& fixed) const;
		Fixed	operator/(const Fixed& fixed) const;

		Fixed&	operator++();
		Fixed 	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		
		static	Fixed& min(Fixed &a, Fixed &b);
		static	const Fixed& min(const Fixed &a, const Fixed &b);
		static	Fixed& max(Fixed &a, Fixed &b);
		static	const Fixed& max(const Fixed &a, const Fixed &b);
		
		int 	getRawBits(void) const;
		
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif