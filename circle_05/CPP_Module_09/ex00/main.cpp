/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 09:14:41 by nsaillez          #+#    #+#             */
/*   Updated: 2026/04/19 12:09:49 by nsaillez         ###   ########.fr       */
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
	BitcoinExchange test("data.csv", argv[1]);
	return (0);
}