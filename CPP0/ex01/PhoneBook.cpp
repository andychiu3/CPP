/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:06:38 by achiu             #+#    #+#             */
/*   Updated: 2024/11/13 12:13:23 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	// std::cout << "phonebook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "phonebook destructor called" << std::endl;
}

void	PhoneBook::addContact()
{
	Contact		newContact;

	std::cout << "\n";
	newContact.setFirstName(get_input("> Enter first name: "));
	newContact.setLastName(get_input("> Enter last name: "));
	newContact.setNickname(get_input("> Enter nickname: "));
	newContact.setPhoneNumber(get_input("> Enter phone number: "));
	newContact.setDarkestSecret(get_input("> Enter darkest secret: "));
	this->_contact[this->_index % 8] = newContact;
	this->_index++;
	std::cout << "\n";
}

std::string	PhoneBook::truncStr(std::string str, size_t width)
{
	return (str.length() > width ? str.substr(0, width - 1) + '.' : str);
}

void	PhoneBook::printPhoneBook(Contact contact[])
{
	size_t	width = 10;

	std::cout << std::setw(width) << std::right << "Index" << '|'
				<< std::setw(width) << std::right << "first name" << '|'
				<< std::setw(width) << std::right << "last name" << '|'
				<< std::setw(width) << std::right << "nickname" << std::endl;
	std::cout << std::string(width * 4 + 3, '-') << std::endl;
	for (int i = 0; i < 8; i++)
		if (!contact[i].getFirstName().empty())
			std::cout << std::setw(width) << std::right << i + 1 << '|'
						<< std::setw(width) << std::right << truncStr(contact[i].getFirstName(), width) << '|'
						<< std::setw(width) << std::right << truncStr(contact[i].getLastName(), width) << '|'
						<< std::setw(width) << std::right << truncStr(contact[i].getNickname(), width) << std::endl;
	std::cout << "\n";
}

void	PhoneBook::display(Contact contact[], int index)
{
	if (index <= 7 && index >= 0 && !contact[index].getFirstName().empty())
	{
		std::cout << "first name: " << contact[index].getFirstName() << std::endl;
		std::cout << "last name: " << contact[index].getLastName() << std::endl;
		std::cout << "nickname: " << contact[index].getNickname() << std::endl;
		std::cout << "phone number: " << contact[index].getPhoneNumber() << std::endl;
		std::cout << "darkest secret: " << contact[index].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "no saved contact yet" << std::endl;
	std::cout << "\n";
}

void	PhoneBook::searchContact()
{
	int			index;
	std::string	input;

	std::cout << "\n";
	printPhoneBook(this->_contact);
	while (1) {
		if (std::cin.eof()) {
			std::cout << "EOF" << std::endl;
			break ;
		}
		if (this->_contact[0].getFirstName().empty()) {
			std::cout << "empty phonebook" << std::endl;
			std::cout << '\n';
			break ;
		}
		try {
			input = get_input("> enter index: ");
			index = stoi(input);
			if (index <= 8 && index >= 1) {
				display(this->_contact, index - 1);
				break ;
			}
			else
				std::cout << "out of index range" << std::endl;
		}
		catch (const std::invalid_argument&) {
			std::cout << "index means nbr" << std::endl;
		}
		catch (const std::out_of_range&) {
			std::cout << "nbr too large" << std::endl;
		}
	}
}

// didn't handle empty input
// void	PhoneBook::searchContact()
// {
// 	int			index;

// 	printPhoneBook(this->_contact);
// 	while (1) {
// 	std::cout << "enter index: ";
// 		if (std::cin >> index) {
// 			if (index <= 8 && index >= 1) {
// 				display(this->_contact, index - 1);
// 				break ;
// 			}
// 			else
// 				std::cout << "Out of range: enter a valid integer between 1 - 8" << std::endl;
// 		}
// 		else {
// 			std::cin.clear();
// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// 			std::cout << "Invalid input: enter a valid integer between 1 - 8" << std::endl;
// 		}
// 	}
// }
