#include "whatever.hpp"

int	main( void )
{
	{
		int a = 2;
		int b = 3;

		swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << min(a, b) << std::endl;
		std::cout << "max(a, b) = " << max(a, b) << std::endl;

	}
	{
		std::string c = "first";
		std::string d = "second";
		
		swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}
}

// int main()
// {
// 	{
// 		int a = 3;
// 		int b = 5;

// 		swap(a, b);
// 		std::cout << "a: " << a << ", b: " << b << std::endl;
// 		std::cout << "min: " << min(a, b) << std::endl;
// 		std::cout << "max: " << max(a, b) << std::endl;
// 	}
// 	{
// 		char a = '0';
// 		char b = 'a';

// 		swap(a, b);
// 		std::cout << "a: " << a << ", b: " << b << std::endl;
// 		std::cout << "min: " << min(a, b) << std::endl;
// 		std::cout << "max: " << max(a, b) << std::endl;
// 	}
// }