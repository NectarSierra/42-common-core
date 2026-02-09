/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:09:19 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/09 17:16:04 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	Span sp = Span(3);

	sp.addNumber(3);
	sp.addNumber(3);
	
	

	// std::vector<unsigned int> test;

	// test.reserve(10);
	// std::vector<unsigned int>::iterator it = test.begin();
	
	// it++;
	// if (it == test.end())
	// 	std::cout << "problem" << std::endl;
	
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	return (0);
}