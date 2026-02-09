/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:09:45 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/09 17:15:41 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	elements.reserve(N);
	//elements.push_back(6);
	//std::cout << elements[0] << std::endl;
	//this->it = elements.end();
	it = elements.begin();
}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span()
{
}

Span& Span::operator=(const Span& other)
{
	this->it = other.it;
	this->elements = other.elements;
	return (*this);
}

void Span::addNumber(unsigned int N)
{
	if (it != elements.end())
		this->elements.insert(it, N);
	else
	  	throw std::out_of_range("Span is full");
	it++;
}

unsigned int Span::shortestSpan(void)
{
	// unsigned int smallest_diff = -1;

	// if (it < 2)
	// 	throw NotEnoughElements();
	
	// for (unsigned int i = 0; i < it; i++)
	// {
	// 	for (unsigned int j = 0; j < it; j++)
	// 	{
	// 		if (i != j)
	// 		{
	// 			if (elements[i] - elements[j] < smallest_diff)
	// 				smallest_diff = elements[i] - elements[j];
	// 		}
	// 	}
	// }
	// return (smallest_diff);
	return (0);
}

unsigned int Span::longestSpan(void)
{

	// unsigned int min = elements[0];
	// unsigned int max = elements[0];
	
	// for (unsigned int i = 0; i < it; i++)
	// {
	// 	if (elements[i] < min)
	// 		min = elements[i];
	// }
	// for (unsigned int i = 0; i < it; i++)
	// {
	// 	if (elements[i] > max)
	// 		max = elements[i];
	// }
	// return (max - min);
	return (0);
}

const char* Span::NotEnoughElements::what() const throw()
{
	return ("Not enough elements");
}