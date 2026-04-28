/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:13:47 by nsaillez          #+#    #+#             */
/*   Updated: 2026/04/28 08:55:04 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[31m" << "Error: wrong usage of program; ./RPN <reverse polish notation>" << "\033[0m" << std::endl;
		return (1);
	}
	if (argv[1] != NULL)
	{
		std::string str(argv[1]);
		RPN test(str);
		test.calculate();
	}
	return (0);
}