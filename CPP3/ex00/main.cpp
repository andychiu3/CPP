#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap a("A");
	ClapTrap* b = new ClapTrap("B");

	std::cout << "\nb4 movement" << std::endl;
	a.prntStatus();
	b->prntStatus();

	b->attack(a.getName());
	a.takeDamage(b->getAttackDamage());
	a.beRepaired(10);
	std::cout << "\nafter movement" << std::endl;
	a.prntStatus();
	b->prntStatus();

	delete b;
	return (0);
}
