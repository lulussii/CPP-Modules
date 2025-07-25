/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:43:29 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/24 08:59:03 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria *_inventory[4];

	public :
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);	
};

#endif