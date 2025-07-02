#pragma once

#include <iostream> // which includes <string>
#include <string>

#define MULTIPLIER 1103515245
#define INCREMENT 12345
#define MODULO_MASK 0x7fffffff
typedef std::string str;

class Brain {
	private:
		str	_idea[100];
		static unsigned int	_id;
		
	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& copy);
		~Brain();

		str	getIdea(unsigned int i) const;
		unsigned int genRanNbr(); // LCG
		str	genRanStr(int length);
} ;
