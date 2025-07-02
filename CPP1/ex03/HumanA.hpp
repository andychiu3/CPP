/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu <achiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:11:55 by achiu             #+#    #+#             */
/*   Updated: 2024/11/12 13:20:50 by achiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class	HumanA {
	private:
		std::string	_name;
		Weapon&		_weapon;

	public:
		HumanA(std::string n, Weapon& type);
		~HumanA();

		void		attack();
} ;

#endif
