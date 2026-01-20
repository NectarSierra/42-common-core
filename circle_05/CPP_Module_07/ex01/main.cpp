/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:58:11 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/19 13:55:21 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void test2( const char &addrs_test)
{
	std::cout << addrs_test << std::endl;
}

void test( char &addrs_test)
{
	addrs_test += 1;
	std::cout << addrs_test << std::endl;
}

int main()
{
	char i[3] = {'h', 'c', 'k'};
	
	::iter(i, 3, ::const_print);
	::iter(i, 3, ::non_const_print);
	::iter(i, 3, test);
	::iter(i, 3, test2);
}