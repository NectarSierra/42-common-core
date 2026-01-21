/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 08:47:58 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/21 12:31:58 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <class T>
class Array
{
	private:
		unsigned int array_size;
		T *array;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();
		
		Array& operator=(Array& other) const;
		T& operator[](unsigned int index);

		unsigned int size(void) const;
		void print_arr(void) const;
		void add_one_to_all(void);
		
	public:
		class Out_of_bounds : public std::exception
		{
			private:
				const char* what() const throw();
		};
};
#include "Array.tpp"

#endif