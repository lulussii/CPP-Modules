/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:08:10 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/24 08:09:08 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
		
	public:
		AMateria(std::string const& type);

		AMateria(const AMateria& other);
		
		virtual ~AMateria();

		AMateria& operator=(const AMateria& other);

		std::string const& getType() const;

		virtual AMateria* clone() const = 0;
		virtual	void use(ICharacter& target);
};

#endif