/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:05:42 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/30 13:36:39 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <deque>
#include <ctime>

class PmergeMe
{
	private :
		std::vector<int>	vectorContainer;
		std::deque<int>		dequeContainer;
		
		std::clock_t		vectorStart;
		std::clock_t		dequeStart;

	public :
		void	parseNumbers(int argc, char **argv);
		void	vectorFordJohnsonAlgo();
		void	dequeFordJohnsonAlgo();
		void	printBefore(void);
		void	printAfter();
		void	vectorAlgo(void);
		void	dequeAlgo(void);
};

#endif