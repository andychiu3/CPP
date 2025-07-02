#include "ScavTrap.hpp"
#include "color.hpp"

ScavTrap::ScavTrap()
	: ClapTrap() {
	std::cout << GREEN << "ScavTrap default constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name) {
	std::cout << GREEN << "ScavTrap para constructor called" << RESET << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << GREEN << "ScavTrap destructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
	: ClapTrap(copy) {
	std::cout << GREEN << "ScavTrap copy constructor called" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	ClapTrap::operator=(other);
	if (this != &other) {
		std::cout << GREEN << "ScavTrap copy assigned constructor called" << RESET << std::endl;
		// _name = other._name;
		// _hitPoints = other._hitPoints;
		// _energyPoints = other._energyPoints;
		// _attackDamage = other._attackDamage;
		_inGuard = other._inGuard;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		std::cout << GREEN << "ScavTrap" << _name << RESET << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		ClapTrap::attack(target);
}

void	ScavTrap::guardGate() {
	std::cout << GREEN << "ScavTrap" << _name << " is now in gate keeper mode" << RESET << std::endl;
}
