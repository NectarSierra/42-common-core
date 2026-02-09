/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 09:09:34 by nsaillez          #+#    #+#             */
/*   Updated: 2026/02/09 09:54:49 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

class Span
{
	private:
		unsigned int N;
	public:
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span& operator=(const Span& other);

		void addNumber(unsigned int N);
};

#endif