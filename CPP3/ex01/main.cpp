#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int	main() {
	ScavTrap	a;
	ClapTrap	b("B");
	ScavTrap*	c = new ScavTrap("C");
	
	std::cout << "\n" << "==DEFAULT STATUS==" << std::endl;
	a.prntStatus();
	b.prntStatus();
	c->prntStatus();

	c->attack(b.getName());
	b.takeDamage(c->getAttackDamage());
	b.beRepaired(5);
	c->guardGate();
	std::cout << "\n==AFTER MOVEMENT==" << std::endl;
	a.prntStatus();
	b.prntStatus();
	c->prntStatus();

	delete c;
}
