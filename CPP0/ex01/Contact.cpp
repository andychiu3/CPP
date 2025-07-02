/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:10:46 by achiu             #+#    #+#             */
/*   Updated: 2024/11/18 10:02:10 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	// std::cout << "contact constructor called" << std::endl;
}

Contact::~Contact(){
	// std::cout << "contact destructor called"<< std::endl;
}

std::string	Contact::getFirstName() const{
	return (this->_firstName);
}

std::string	Contact::getLastName() const{
	return (this->_lastName);
}

std::string	Contact::getNickname() const{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber() const{
	return (this->_phoneNumber);
}
std::string	Contact::getDarkestSecret() const{
	return (this->_darkestSecret);
}

void	Contact::setFirstName(std::string str){
	this->_firstName = str;
}

void	Contact::setLastName(std::string str){
	this->_lastName = str;
}

void	Contact::setNickname(std::string str){
	this->_nickname = str;
}

void	Contact::setPhoneNumber(std::string str){
	this->_phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str){
	this->_darkestSecret = str;
}