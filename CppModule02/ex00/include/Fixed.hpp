/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:12:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/30 13:43:55 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int 				_rawBits;
		static const int	_fractionnalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& autre);

		~Fixed();
		
		Fixed& 	operator=(const Fixed& autre);
		
		int 	getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif