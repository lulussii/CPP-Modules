/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:31:36 by lserodon          #+#    #+#             */
/*   Updated: 2026/02/25 17:57:49 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {

	private :
		T* 				_array;
		unsigned int	_size;
	
	public :

	Array();
	Array(unsigned int n);
	Array(const Array& other);

	~Array();
	
	Array& operator=(const Array& other);

	T& operator[](unsigned int index);
	const	T& operator[](unsigned int index) const;

	unsigned int size() const;

	class	OutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Index out of bounds !";
			}
	};
	
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	this->_array = new T[this->_size]();
}

template <typename T>
Array<T>::Array(const Array<T>& other) : _size(other._size)
{
	this->_array = new T[this->_size]();

	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_size = other._size;
		this->_array = new T[this->_size]();

		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Array<T>::OutOfBoundsException();
	return (this->_array[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw Array<T>::OutOfBoundsException();
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

#endif