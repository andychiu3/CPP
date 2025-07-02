/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:01:19 by achiu             #+#    #+#             */
/*   Updated: 2024/11/18 10:02:15 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

class	PhoneBook{
	private:
		int			_index;
		Contact		_contact[8];
		
	public:
		PhoneBook();
		~PhoneBook();
		void		addContact();
		void		searchContact();

		void		printPhoneBook(Contact contact[]);
		std::string	truncStr(std::string str, size_t width);
		void		display(Contact contact[], int index);
} ;

std::string	get_input(const std::string& prompt);

#endif
