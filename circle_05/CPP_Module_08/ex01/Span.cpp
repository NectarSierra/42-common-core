/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:09:45 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/09 12:29:26 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->elements = new unsigned int[N];
	this->end = N;
	this->it = 0;
}

Span::Span(const Span& other)
{
	*this = other;
}

Span::~Span()
{
	delete[] this->elements;
}

Span& Span::operator=(const Span& other)
{
	
	this->elements = other.elements;
	this->end = other.end;
	this->it = other.it;
	return (*this);
}

void Span::addNumber(unsigned int N)
{
	if (this->it == end)
		throw std::out_of_range("Span is full");
	this->elements[this->it++] = N;
}