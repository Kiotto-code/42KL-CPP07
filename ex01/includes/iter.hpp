#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include "Color.hpp"

template <typename T, typename F>
// void iter(T *arr, unsigned arr_len, F func)
// {
//     for (unsigned i = 0; i < arr_len; i++)
//         func(arr[i]);
// }
void	iter(T *arr, unsigned arr_len, F func)
{
	// std::cout << arr[0] << std::endl;
	for (size_t i = 0; i < arr_len; i++)
		func(arr[i]);
}

// void	iter(T *arr, unsigned arr_len, F *func);

#endif