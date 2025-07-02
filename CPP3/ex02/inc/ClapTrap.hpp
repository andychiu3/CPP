#pragma once

#include <iostream>

class	ClapTrap {
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& other);
		virtual	~ClapTrap();

		std::string getName() const;
		unsigned int getAttackDamage() const;
		
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int ammount);
		void beRepaired(unsigned int amount);

		void prntStatus() const;
} ;
