/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu <achiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:48:52 by achiu             #+#    #+#             */
/*   Updated: 2024/11/11 16:39:38 by achiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// default constructor
Zombie::Zombie(){
	std::cout << "default constructor called" << std::endl;
}

// Parameterized constructor
Zombie::Zombie(std::string name){
	this->_name = name;
	std::cout << "Parameterized constructor called" << std::endl;
}

// destructor
Zombie::~Zombie(){
	std::cout << this->_name << " destroyed" << std::endl;
}

void	Zombie::announce(void){
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
