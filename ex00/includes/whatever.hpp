#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

// template<typename T1, typename T2>
// void swap (T1 &a, T2 &b)
// {
// 	T1 tmp = a;
// 	a = b;
// 	b = tmp;
// }
template<typename T>
void swap (T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min (T num1, T num2)
{
	return ((num1 > num2)? num2: num1);
}

template<typename T>
T max (T num1, T num2)
{
	return ((num1 > num2)? num1: num2);
}

#endif