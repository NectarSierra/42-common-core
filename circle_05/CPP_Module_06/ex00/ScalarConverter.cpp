/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:49:20 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/12 09:53:06 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "header.hpp"

void ScalarConverter::convert(std::string type)
{
	if (type == "nan")
		return nan(atof(type.c_str()));
	if (type == "nanf")
		return nanf(atof(type.c_str()));
	if (!type.compare("inff") || !type.compare("+inff") || !type.compare("-inff"))
		return inf(atof(type.c_str()));
	if (!type.compare("inf") || !type.compare("+inf") || !type.compare("-inf"))
		return inff(atof(type.c_str()));
	std::cout << std::setprecision(1) << std::fixed;
	find_type(type);
}


