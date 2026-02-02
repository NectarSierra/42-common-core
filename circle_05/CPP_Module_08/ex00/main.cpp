/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:16:23 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/02 13:44:37 by nsaillez         ###   ########.fr       */
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
	
	std::set<int>::iterator it = easyfind(array, 0);
	std::cout << *it << '\n';
	
	it = array.find(0);
	std::cout << *it << '\n';
	
	return (0);
}