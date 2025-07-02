/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu <achiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:10:05 by achiu             #+#    #+#             */
/*   Updated: 2024/11/11 18:02:51 by achiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	// std::cout << "constructor called" << std::endl;
}

Zombie::Zombie(std::string name) {
	this->_name = name;
	// std::cout << "para constructor called" << std::endl;
	announce();
}

Zombie::~Zombie() {
	std::cout << this->_name << " destroyed" << std::endl;
}

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
