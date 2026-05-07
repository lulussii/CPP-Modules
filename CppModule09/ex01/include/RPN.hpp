/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:35:03 by lserodon          #+#    #+#             */
/*   Updated: 2026/05/07 13:20:11 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <stdexcept>
#include <climits>

class RPN
{
	private :
		std::stack<int>		numbers;
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		
	public :
		RPN();
		~RPN();
		void parseOperation(char *argv);
		void calculateOperation(char sign);

};

#endif