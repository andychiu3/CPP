/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu <achiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:12:20 by achiu             #+#    #+#             */
/*   Updated: 2024/11/12 12:15:29 by achiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: _name(name), _weapon(nullptr) {}

HumanB::~HumanB() {
	std::cout << "HumanB " << this->_name << " vanished" << std::endl;
}

void	HumanB::attack() 
{
	if (_weapon)
		std::cout << _name << " attacks with their " 
			<< _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& type) {
	_weapon = &type;
}