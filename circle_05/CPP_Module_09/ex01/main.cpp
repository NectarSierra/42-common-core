/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:13:47 by nsaillez          #+#    #+#             */
/*   Updated: 2026/04/20 11:40:02 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[31m" << "Wrong usage of program!" << "\033[0m" << std::endl;
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