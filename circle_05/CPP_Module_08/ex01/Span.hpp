/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:09:34 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/09 12:24:06 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <exception>

class Span
{
	private:
		unsigned int *elements;
		unsigned int end;
		unsigned int it;
	public:
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void addNumber(unsigned int N);
};

#endif