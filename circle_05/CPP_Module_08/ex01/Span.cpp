/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:09:45 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/10 08:59:00 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	max_index = N;
	elements.reserve(N);
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
	max_index = other.max_index;
	elements = other.elements;
	return (*this);
}

void Span::addNumber(unsigned int N)
{
	if (elements.size() == max_index)
		throw std::out_of_range("Span is full");
	else
		elements.push_back(N);
	(void)N;
}

unsigned int Span::shortestSpan(void)
{
	if (elements.size() < 2)
		throw NotEnoughElements();
	std::vector<unsigned int> sorted = elements;
	std::sort(sorted.begin(), sorted.end());
	unsigned int diff = sorted[0 + 1] - sorted[0];
	for (unsigned int i = 0; i < sorted.size() - 1; i++)
	{
		if (sorted[i + 1]-sorted[i] < diff)
			diff = sorted[i + 1] - sorted[i];
	}
	return (diff);
}

unsigned int Span::longestSpan(void)
{
	if (elements.size() < 2)
		throw NotEnoughElements();

	unsigned int min = *std::min_element(elements.begin(), elements.end());
	unsigned int max = *std::max_element(elements.begin(), elements.end());

	return (max - min);
}

const char* Span::NotEnoughElements::what() const throw()
{
	return ("Not enough elements");
}

void Span::addRangeNumbers(std::vector<unsigned int>::iterator begin,
						std::vector<unsigned int>::iterator end)
{
	for (std::vector<unsigned int>::iterator it = begin; it != end; it++)
	{
		if (elements.size() == max_index)
			throw std::out_of_range("Span is full");
		else
			elements.push_back(*it);
	}
}

void Span::printElements()
{
	for (std::vector<unsigned int>::iterator it = elements.begin(); it != elements.end(); it++)
	{
		std::cout << "[" << *it << "]";
	}
	std::cout << std::endl;
}