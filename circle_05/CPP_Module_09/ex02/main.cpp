/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:19:19 by nsaillez          #+#    #+#             */
/*   Updated: 2026/05/18 12:54:40 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <vector>

int parse(char *str)
{
	char* end;
	long tmp;
	
	tmp = strtol(str, &end, 0);
	if (*end != '\0' || end == str)
	{
		std::cout << "\033[31mError: Non-digit detected\033[0m" << std::endl;
		return (-1);
	}
	if (tmp < 0)
	{
		std::cerr << "\033[31mError: Negative number detected\033[0m" << std::endl;
		return (-1);
	}
	if (errno == ERANGE || tmp > __INT_MAX__)
	{
		std::cerr << "\033[31mError: Overflow detected\033[0m" << std::endl;
		return (-1);
	}
	return (static_cast<int>(tmp));
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Wrong usage of program!" << std::endl;
		return (1);
	}
	std::vector<int> arr1;
	for (int i = 1; i < argc; i++)
	{
		int tmp = parse(argv[i]);
		if (tmp < 0)
			return (1);
		for (int j = 0; static_cast<size_t>(j) < arr1.size(); j++)
		{
			if ((i - 1) != j && tmp == arr1[j])
			{
				std::cout << "\033[31mError: Duplicates detected\033[0m" << std::endl;
				return (1);
			}
			
		}
		arr1.push_back(tmp);
	}
	std::cout << "Before:";
	for (int i = 0; i < argc - 1; i++)
		std::cout << " " << arr1[i];
	std::cout << std::endl;
	// parsing (int, only +, detect overflow)
	
	return (0);
}