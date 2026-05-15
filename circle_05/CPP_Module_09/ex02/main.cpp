/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:19:19 by nsaillez          #+#    #+#             */
/*   Updated: 2026/05/15 12:02:21 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cerrno>
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Wrong usage of program!" << std::endl;
		return (1);
	}
	char* end;
	long tmp;
	tmp = strtol(argv[1], &end, 0);
	if (*end != '\0' || end == argv[1])
		std::cout << "Invalid" << std::endl;
	if (tmp < 0)
		std::cerr << "No negative number allowed!" << std::endl;
	if (errno == ERANGE || tmp > __INT_MAX__)
		std::cerr << "Overflow" << std::endl;
	std::cout << tmp;
	// parsing (int, only +, detect overflow)
	
	return (0);
}