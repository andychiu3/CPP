#pragma once

#include <iostream>

class	WrongAnimal {
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		WrongAnimal& operator=(const WrongAnimal& copy);
		virtual ~WrongAnimal();

		std::string	getType() const;
		void	makeSound() const;
} ;
