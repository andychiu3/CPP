#include "FragTrap.hpp"
#include "color.hpp"

FragTrap::FragTrap() 
	: ClapTrap() {
	std::cout << YELLOW << "FragTrap default constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) 
	: ClapTrap(name) {
	std::cout << YELLOW << "FragTrap para constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) 
	: ClapTrap(copy) {
	std::cout << YELLOW << "FragTrap copy constructor called" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	std::cout << YELLOW << "FragTrap copy assign constructor called" << RESET << std::endl;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << YELLOW << "FragTrap destructor called" << RESET << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		std::cout << YELLOW << "FragTrap" << _name << RESET << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		ClapTrap::attack(target);
}

void	FragTrap::highFivesGuys() {
	std::cout << YELLOW << "FragTrap" << _name << ": high fives guys" << RESET << std::endl;
}
