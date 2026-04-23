/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:35:03 by lserodon          #+#    #+#             */
/*   Updated: 2026/04/21 12:35:53 by lserodon         ###   ########.fr       */
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
    
    public :
        void parseOperation(char *argv);
		void calculateOperation(char sign);
};

#endif