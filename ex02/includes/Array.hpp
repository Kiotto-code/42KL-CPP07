#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array{
	private:
		T *m_array;
		unsigned len;

	public:
		Array();
		Array(unsigned);
		Array(const Array &src);
		~Array();

		const T *getArray(void) const;

		Array &operator = (Array const &src);
		T &operator [] (int i);

		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif