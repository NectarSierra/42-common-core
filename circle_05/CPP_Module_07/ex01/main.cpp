/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:58:11 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/20 08:57:01 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void non_const_test( const char &addrs_test)
{
	std::cout << addrs_test << std::endl;
}

void const_test( char &addrs_test)
{
	addrs_test += 1;
	std::cout << addrs_test << std::endl;
}

int main()
{
	char i[4] = {'N', 'I', 'C', 'E'};
	
	::iter(i, sizeof(i), ::const_print); // NICE
	::iter(i, sizeof(i), ::non_const_print); // OJDF
	
	::iter(i, sizeof(i), non_const_test); // PKEG
	::iter(i, sizeof(i), const_test); // PKEG
}