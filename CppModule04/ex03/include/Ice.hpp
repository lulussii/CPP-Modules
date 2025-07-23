/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:13:41 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/23 08:24:59 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);

		~Ice();

		Ice& operator=(const Ice& other);
		std::string const& getType() const;

		Ice* clone() const;
		void	use(ICharacter& target);
};

#endif