/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:01:05 by achiu             #+#    #+#             */
/*   Updated: 2024/11/18 10:01:45 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class	Contact{
	private:
		std::string	_firstName;
		std::string _lastName;
		std::string	_nickname;
		std::string _phoneNumber;
		std::string	_darkestSecret;
		
	public:
		Contact();
		~Contact();

		std::string	getFirstName() const; // getter
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;

		void		setFirstName(std::string); // setter
		void		setLastName(std::string);
		void		setNickname(std::string);
		void		setPhoneNumber(std::string str);
		void		setDarkestSecret(std::string str);
} ;

#endif
