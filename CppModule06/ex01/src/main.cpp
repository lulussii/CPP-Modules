/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:54:54 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/20 11:27:44 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int main(void)
{
	Data data;
	data.data = 42;
	data.name = "test";

	std::cout << "--- INITIAL STATE---" << std::endl;
	std::cout << "Original adress (&data) : " << &data << std::endl;
	std::cout << "Data.data : " << data.data << std::endl;
	std::cout << "Data.name : " << data.name << std::endl;
	std::cout << std::endl;

	uintptr_t rawPtr = Serializer::serialize(&data);

	std::cout << "--- AFTER SERIALIZE---" << std::endl;
	std::cout << "Value of uintptr_t : " << rawPtr << std::endl;
	std::cout << std::endl;

	Data *deserializedPtr = Serializer::deserialize(rawPtr);
	
	std::cout << "--- AFTER DESERIALIZE ---" << std::endl;
	std::cout << "New pointer adress : " << deserializedPtr << std::endl;
	std::cout << "Data.data : " << deserializedPtr->data << std::endl;
	std::cout << "Data.name : " << deserializedPtr->name << std::endl;
	std::cout << std::endl;

	return 0;
}