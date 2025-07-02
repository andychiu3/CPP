#include "Serializer.hpp"

int	main(void) {
	// Serializer cannotinstantiate;
	Data	*whatever = new Data;
	std::cout << "original address:\n" << whatever << "\n" << std::endl;

	uintptr_t	serialized = Serializer::serialize(whatever);
	std::cout << "address -> numbers:\n" << serialized << "\n" << std::endl;

	serialized++;
	Data	*deserialized = Serializer::deserialize(serialized);
	std::cout << "numbers++ -> address:\n" << deserialized << "\n" << std::endl;

	Data	*tmp = whatever;
	std::cout << "original address++:\n" << ++tmp << "\n" << std::endl;

	std::cout << "original address after serilaization and deserialization:\n" << whatever << "\n" << std::endl;

	delete	whatever;
}
