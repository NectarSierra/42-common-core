/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:09:19 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/10 09:02:09 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	Span sp = Span(1000);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	Span sp2 = Span(10000);
	for (int i = 0; i < 10000 - 1; i++)
		sp2.addNumber(123);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<unsigned int> vect;
	vect.push_back(6);
	vect.push_back(3);
	vect.push_back(17);
	vect.push_back(9);
	vect.push_back(11);
	
	sp.addRangeNumbers(vect.begin(), vect.end());
	sp.addRangeNumbers(vect.begin(), vect.end());
	sp.addRangeNumbers(vect.begin(), vect.end());

	sp.printElements();
	return (0);
}