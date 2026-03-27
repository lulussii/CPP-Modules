/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:03:30 by lserodon          #+#    #+#             */
/*   Updated: 2026/03/27 10:05:09 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
	private :
		std::map<std::string, float> data;
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange operator=(const BitcoinExchange &other);
		
	public :
		BitcoinExchange();
		~BitcoinExchange();
		
		void	parseData();
		void 	parseFile(char *argv);
		void	displayLine(std::string date, float value);
};

class BadInputException : public std::exception
{
	private:
		std::string _message;

	public:
		BadInputException(const std::string &msg) : _message("Error: bad input => " + msg) {}
		virtual ~BadInputException() throw() {}
		virtual const char* what() const throw()
		{
			return (_message.c_str());
		}
};

#endif