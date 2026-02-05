/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:16:23 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/05 14:40:10 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <set>
#include "easyfind.hpp"
int main(void)
{
	std::set<int> array;
	array.insert(1);
	array.insert(5);
	array.insert(4);
	
	try
	{
		std::set<int>::iterator it = easyfind(array, 0);
		std::cout << *it << '\n';
		it = array.find(0);
		std::cout << *it << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}
	return (0);
}