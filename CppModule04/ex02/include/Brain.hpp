/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:14:37 by lserodon          #+#    #+#             */
/*   Updated: 2025/07/22 11:49:48 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private :
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		
		~Brain();
		
		Brain& operator=(const Brain& other);

		const std::string &getIdea(int index) const;
		void	setIdea(std::string idea, int index);
};

#endif