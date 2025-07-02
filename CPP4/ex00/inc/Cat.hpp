#pragma once

#include "Animal.hpp"

class	Cat : public Animal {
	private:

	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& other);
		virtual ~Cat();

		virtual void	makeSound() const;
};
