#include "ClapTrap.hpp"
#include "color.hpp"

ClapTrap::ClapTrap() 
	:  _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << RED << "ClapTrap default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
		std::cout << RED << "ClapTrap para constructor called" << RESET << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap& copy) 
	:  _name(copy._name), _hitPoints(copy._hitPoints), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage) {
	std::cout << RED << "ClapTrap copy constructor called" << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "ClapTrap destructor called" << RESET << std::endl;
}

std::string	ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

// we may need a getter in order to call
void	ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0)
		std::cout << RED << "dead one cannot attack" << RESET << std::endl;
	else if (this->_energyPoints > 0) {
		this->_energyPoints--;
		std::cout << RED << "ClapTrap " << _name << RESET << " attacks " << target 
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << _name << " got no energy to move" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0) {
		if (amount > _hitPoints)
			_hitPoints = 0;
		else
			this->_hitPoints -= amount;
		std::cout << _name << " takes damage " << amount << std::endl;
	}
	else
		std::cout << _name << " already dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0)
		std::cout << "dead got nothing to repair" << std::endl;
	else if (_energyPoints > 0) {
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << _name << " is repairing " << amount << std::endl;
	}
	else
		std::cout << "no energy to do anything" << std::endl;
}

void ClapTrap::prntStatus() const {
	std::cout << "\n" << _name << "\n" 
		<< "_hitPoints: " << _hitPoints << "\n" 
		<< "_energyPoints: " << _energyPoints << "\n" 
		<< "_attackDamage: "<< _attackDamage << "\n" << std::endl;
}