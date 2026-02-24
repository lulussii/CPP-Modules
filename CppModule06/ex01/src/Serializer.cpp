/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:18:13 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/20 11:50:50 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

Serializer& Serializer::operator=(const Serializer& other) 
{
	(void) other;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t res;

	res = reinterpret_cast<uintptr_t>(ptr);
	return (res);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data	*res;

	res = reinterpret_cast<Data *>(raw);
	
	return (res);
}
