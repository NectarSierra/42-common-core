/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 08:47:58 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/21 11:38:28 by nsaillez         ###   ########.fr       */
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
		Array(Array& other);
		~Array();
		
		Array& operator=(Array& other);
		T& operator[](unsigned int index);

		unsigned int size(void);
		void print_arr(void);
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