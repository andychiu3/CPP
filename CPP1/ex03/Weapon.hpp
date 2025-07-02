/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:11:25 by achiu             #+#    #+#             */
/*   Updated: 2024/11/17 09:38:04 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class	Weapon {
	private:
		std::string			_type;

	public:
		Weapon(std::string type);
		~Weapon();

		const std::string&	getType() const;
		void				setType(std::string	newOne);
} ;

#endif
