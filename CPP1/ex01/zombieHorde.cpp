/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achiu <achiu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:51:55 by achiu             #+#    #+#             */
/*   Updated: 2024/11/11 18:07:32 by achiu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){

	Zombie*	ptr = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		new (&ptr[i]) Zombie(name); // may have to use SETTER
	return (ptr);
}
