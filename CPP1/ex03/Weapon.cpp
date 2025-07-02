/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:11:37 by achiu             #+#    #+#             */
/*   Updated: 2024/11/17 09:38:14 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) 
	: _type(type) 
	{
		std::cout << "constructor called" << std::endl;
	}

Weapon::~Weapon() {
	std::cout << "destructor called" << std::endl;
}

const std::string& Weapon::getType() const{
	return (this->_type);
}

void	Weapon::setType(std::string newOne) {
	this->_type = newOne;
}
