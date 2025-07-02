/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu <achiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:12:13 by achiu             #+#    #+#             */
/*   Updated: 2024/11/12 13:20:48 by achiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class	HumanB {
	private:
		std::string	_name;
		Weapon*		_weapon;

	public:
		HumanB(std::string n);
		~HumanB();

		void		setWeapon(Weapon& type);
		void		attack();
} ;

#endif
