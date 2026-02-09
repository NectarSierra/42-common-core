/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:09:34 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/09 16:58:55 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>


class Span
{
	private:
		std::vector<unsigned int> elements;
		std::vector<unsigned int>::iterator it;
	public:
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void addNumber(unsigned int N);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

	class NotEnoughElements : public std::exception
	{
		private:
			const char* what() const throw();
	};
};

#endif