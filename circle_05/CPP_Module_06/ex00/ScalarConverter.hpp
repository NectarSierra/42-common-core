/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:49:47 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/12 10:12:59 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(ScalarConverter& other);
	public:
		static void convert(std::string type);
	private:
		static void nanf(float data);
		static void inff(double data);
		static void nan(float data);
		static void inf(double data);
		static int	overflow_check(int res, int digit, int isneg);
		static int	char_to_int_overflow(const char *str);
		static void print_char_type(char data);
		static void print_int_type(int data);
		static void print_float_type(double data);
		static void print_double_type(double data);
		static void find_type(std::string type);
};

#endif 