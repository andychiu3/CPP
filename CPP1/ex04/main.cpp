/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fiftyblue <fiftyblue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:33:47 by achiu             #+#    #+#             */
/*   Updated: 2024/11/13 20:29:24 by fiftyblue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replace_(char **av, std::string& content)
{
	std::ofstream	file((std::string(av[1]) + ".replace").c_str());
	if (!file.is_open()) {
		std::cerr << "Error: fail creating replacing file" << std::endl;
		return ;
	}

	for (size_t i = 0; i < content.size(); i++)
	{
		size_t	pos = content.find(av[2], i);
		if (pos != std::string::npos && pos == i) {
			file << av[3];
			i += std::string(av[2]).size() - 1;
		}
		else
			file << content[i];
	}

	file.close();
}

int	main(int ac, char **av)
{
	std::string		content;
	char			c;

	if (ac == 4)
	{
		std::ifstream	file(av[1]);
		if (!file.is_open()) {
			std::cerr << "Error: " << av[1] << " no such file or directory" << std::endl;
			return (1);
		}
		while (file.get(c))
			content += c;
		file.close();
		// std::cout << "file content: " << std::endl;
		// std::cout << content << std::endl;
		replace_(av, content);
		return (0);
	}
	else
		std::cerr << "<filename> <old content> <new content>" << std::endl;
	return (1);
}