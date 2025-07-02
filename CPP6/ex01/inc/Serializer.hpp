#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

struct	Data {
	void	*ptr;
}	;

class Serializer {
	private:
		Serializer();

	public:
		Serializer(const Serializer& copy);
		Serializer operator=(const Serializer& other);
		~Serializer();

		static	uintptr_t	serialize(Data *ptr);
		static Data	*deserialize(uintptr_t raw);
}	;
