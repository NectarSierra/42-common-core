/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:14:41 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/24 08:34:25 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "\033[31m" << "[Error] " << "\033[0m" << "Wrong usage of program, please use => ./btc [FILE]" << std::endl;
		return (-1);
	}
	else
	{
		BitcoinExchange test("data.csv", argv[1]);
		(void)argv;
	}
}