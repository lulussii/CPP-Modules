/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:13:41 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/23 13:42:47 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);

		~Cure();

		Cure& operator=(const Cure& other);

		Cure* clone() const;
		void	use(ICharacter& target);
};

#endif