#pragma once

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	private:

	public:
		WrongCat();
		WrongCat(const WrongCat& copy);
		WrongCat& operator=(const WrongCat& other);
		~WrongCat();

		void	makeSound() const;
};
