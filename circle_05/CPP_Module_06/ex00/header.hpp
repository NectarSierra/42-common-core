/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:47:53 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/12 09:53:37 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

void nanf(float data);
void inff(double data);
void nan(float data);
void inf(double data);
int	overflow_check(int res, int digit, int isneg);
int	char_to_int_overflow(const char *str);
void print_char_type(char data);
void print_int_type(int data);
void print_float_type(double data);
void print_double_type(double data);
void find_type(std::string type);

#endif