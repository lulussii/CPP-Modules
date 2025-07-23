/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:08:10 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/23 08:13:33 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string const& type);

		AMateria(const AMateria& other);
		
		~AMateria();

		AMateria& operator=(const AMateria& other);

		std::string const& getType() const;

		virtual AMateria* clone() const = 0;
		virtual	void use(ICharacter& target);
};

#endif