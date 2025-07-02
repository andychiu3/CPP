#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ClapTrap	a;
	ScavTrap	b("B");
	FragTrap*	c = new FragTrap("C");
	// FragTrap	d = *c;

	std::cout << "\n==DEFAULT STATUS==" << std::endl;
	a.prntStatus();
	b.prntStatus();
	c->prntStatus();
	// d.prntStatus();

	b.attack("C");
	c->takeDamage(b.getAttackDamage());
	b.guardGate();
	c->highFivesGuys();
	c->attack("default");
	a.takeDamage(c->getAttackDamage());
	a.beRepaired(100);

	std::cout << "\n==AFTER MOVEMENT STATUS==" << std::endl;
	a.prntStatus();
	b.prntStatus();
	c->prntStatus();

	delete c;
}