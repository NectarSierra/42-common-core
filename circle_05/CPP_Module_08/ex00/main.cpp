/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:16:23 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/09 08:48:34 by nsaillez         ###   ########.fr       */
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
	
	int needle = 5; 
	try
	{
		std::set<int>::iterator it = easyfind(array, needle);
		std::cout << "easyfind(): " << *it << '\n';
		
		it = array.find(needle);
		std::cout << "Container.find(): " << *it << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: " << e.what() << '\n';
	}
	return (0);
}