/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:09:34 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/09 18:23:06 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>


class Span
{
	private:
		unsigned int max_index;
		std::vector<unsigned int> elements;
	public:
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void addNumber(unsigned int N);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

		void addRangeNumbers(std::vector<unsigned int>::iterator begin,
							std::vector<unsigned int>::iterator end);

	class NotEnoughElements : public std::exception
	{
		private:
			const char* what() const throw();
	};
};

#endif