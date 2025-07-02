#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <exception>

#define BLUE "\033[36m"
#define RESET "\033[0m"

template<typename T>
class Array {
	private:
		T	*_array;
		unsigned int	_size;

	public:
		/* constructor */
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();

		/* operators*/
		Array& operator=(const Array& other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		/* mandatory */
		unsigned int size() const;

		class outOfRange : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Exception: Index out of range";
				}
		}	;
}	;

#include "./Array.tpp"
#endif
