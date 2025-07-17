/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:28:55 by lserodon          #+#    #+#             */
/*   Updated: 2025/06/25 10:52:12 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
		
	public:
		std::string askForField(const std::string& fieldName);
		std::string truncateField(const std::string& str) const;
		void	displayContactSummary(int index) const;
		void	displayContactDetails() const;
		void	askInfo();
};

#endif