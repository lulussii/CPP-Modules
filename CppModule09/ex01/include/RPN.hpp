/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:35:03 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/26 15:25:42 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
    private :
        std::stack<int>		numbers;
    
    public :
        void parseOperation(char *argv);
		void calculateOperation(char sign);
};

#endif