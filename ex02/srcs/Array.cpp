#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	m_array = nullptr;
}

template <typename T>
Array<T>::Array(unsigned size)
{
	m_array = new int[size];
}

template <typename T>
Array<T>::Array(const Array &src)
{
	this->data = new T[src.len];
	this->len = src.len;

	for (unsigned int i = 0; i < len; i++)
		this->data[i] = src.data[i];
}

template <typename T>
Array<T> &Array<T>::operator = (Array const &src)
{
	if (this->data != NULL)
		delete[] this->data;
	this->data = new T[src.len];
	this->len = src.len;

	for (unsigned int i = 0; i < len; i++)
		this->data[i] = src.data[i];
	
	return *this;
}

template<typename T>
T& Array<T>::operator[](int i)
{
	if (i < 0 || i >= static_cast<int>(this->len))
		throw OutOfBoundsException();
	return m_array[i];
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "[Array] destructor being called" << std::endl;
}

template <typename T>
const T *Array<T>::getArray(void) const
{
	return (m_array);
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array out of bounds";
}