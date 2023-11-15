#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array()
{
	this->len = 0;
	this->m_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned size)
{
	this->len = size;
	m_array = new int[size];
}

template <typename T>
Array<T>::Array(Array const &src)
{
	this->m_array = new T[src.len];
	this->len = src.len;

	for (unsigned int i = 0; i < len; i++)
		this->m_array[i] = src.m_array[i];
}

template <typename T>
Array<T> &Array<T>::operator = (Array const &src)
{
	if (this->m_array != NULL)
		delete[] this->m_array;
	this->m_array = new T[src.len];
	this->len = src.len;

	for (unsigned int i = 0; i < len; i++)
		this->m_array[i] = src.m_array[i];
	
	return *this;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return this->len;
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
	delete[] this->m_array;
}

template <typename T>
const T *Array<T>::getArray(void) const
{
	return (m_array);
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index is out of bounds";
}

#endif