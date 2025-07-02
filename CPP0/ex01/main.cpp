/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:41:02 by achiu             #+#    #+#             */
/*   Updated: 2024/11/13 12:04:07 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

// to solve the case of no input
std::string	get_input(const std::string& prompt)
{
	std::string	input;

	while (input.empty())
	{
		if (std::cin.eof()) {
			std::cout << "EOF" << std::endl;
			break ;
		}
		std::cout << prompt;
		std::getline(std::cin, input);
	}
	return (input);
}

int	main(void)
{
	std::string	line;
	PhoneBook	pb;

	std::cout << "This is a crappy awesome phonebook software" << std::endl;
	std::cout << "The program only accepts ADD, SEARCH and EXIT" << std::endl;
	while (1)
	{
		std::cout << "> Enter command: ";
		if (!std::getline(std::cin, line))
			return (1);
		if (line.empty())
			continue ;
		if (line == "ADD")
			pb.addContact();
		else if (line == "SEARCH")
			pb.searchContact();
		else if (line == "EXIT") {
			std::cout << "The program quits and the contacts are lost forever!" << std::endl;
			break ;
		}
		else
			std::cout << "The program only accepts ADD, SEARCH and EXIT" << std::endl;
	}
	return (0);
}