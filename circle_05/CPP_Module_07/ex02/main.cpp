/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 08:48:00 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/21 11:15:31 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> test;
	test.print_arr();

	Array<int> test2(4);
	Array<int> test3(test2);
	test2.add_one_to_all();
	test2.print_arr();
	test3.print_arr();

	test3 = test2;
	test2.print_arr();
	test3.print_arr();

	return (0);
}