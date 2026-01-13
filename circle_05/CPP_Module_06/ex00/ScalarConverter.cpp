/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:49:20 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/13 10:16:34 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <cstdlib>

void ScalarConverter::nanf(float data)
{
	std::cout << "char: " << "impossible" << "\n";
	std::cout << "int: " << "impossible" << "\n";
	std::cout << "float: " << data << "f\n";
	std::cout << "double: " << static_cast<double>(data) << "\n";
}

void ScalarConverter::inff(double data)
{
	std::cout << "char: " << "impossible" << "\n";
	std::cout << "int: " << "impossible" << "\n";
	std::cout << "float: " << data << "f\n";
	std::cout << "double: " << static_cast<double>(data) << "\n";
}

void ScalarConverter::nan(float data)
{
	std::cout << "char: " << "impossible" << "\n";
	std::cout << "int: " << "impossible" << "\n";
	std::cout << "float: " << static_cast<float>(data) << "f\n";
	std::cout << "double: " << data << "\n";
}

void ScalarConverter::inf(double data)
{
	std::cout << "char: " << "impossible" << "\n";
	std::cout << "int: " << "impossible" << "\n";
	std::cout << "float: " << static_cast<float>(data) << "f\n";
	std::cout << "double: " << data << "\n";
}

int	ScalarConverter::overflow_check(int res, int digit, int isneg)
{
	if (isneg == -1)
	{
		if ((res >= 214748364) && ((res > 214748364) || (digit > 8)))
			return (-1);
	}
	else
	{
		if ((res >= 214748364) && ((res > 214748364) || (digit > 7)))
			return (-1);
	}
	return (0);
}

int	ScalarConverter::char_to_int_overflow(const char *str)
{
	int	i;
	int	res;
	int	isneg;

	i = 0;
	isneg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = -1;
		i++;
	}
	res = 0;
	while ((str[i] >= 48 && str[i] <= 57))
	{
		if (overflow_check(res, (str[i] - '0'), isneg) == -1)
			return (-1);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.' || !(str[i] >= 48 && str[i] <= 57))
		return (0);
	if (str[i] || str[i - 1] == '-' || str[i - 1] == '+')
		return (-1);
	return (0);
}

void ScalarConverter::print_char_type(char data)
{
	// std::cout << "CHAR" << std::endl;
	
	if (data < 32 || data > 126)
		std::cout << "char: " << "Non displayable." << "\n";
	else
		std::cout << "char: " << "'" << data << "'"<< "\n";
	std::cout << "int: " << static_cast<int>(data) << "\n";
	std::cout << "float: " << static_cast<float>(data) << "f\n";
	std::cout << "double: " << static_cast<double>(data) << "\n";
}

void ScalarConverter::print_int_type(int data)
{
	// std::cout << "INT" << std::endl;

	if (data < 32 || data > 126)
		std::cout << "char: " << "Non displayable." << "\n";
	else
		std::cout << "char: " << "'" << static_cast<char>(data) << "'"<< "\n";
	std::cout << "int: " << data << "\n";
	std::cout << "float: " << static_cast<float>(data) << "f\n";
	std::cout << "double: " << static_cast<double>(data) << "\n";
}

void ScalarConverter::print_float_type(double data)
{
	// std::cout << "FLOAT" << std::endl;
	
	if (data < 32 || data > 126)
		std::cout << "char: " << "Non displayable." << "\n";
	else
		std::cout << "char: " << "'" << static_cast<char>(data) << "'"<< "\n";
	std::cout << "int: " << static_cast<int>(data) << "\n";
	std::cout << "float: " << data << "f\n";
	std::cout << "double: " << static_cast<double>(data) << "\n";
}

void ScalarConverter::print_double_type(double data)
{
	// std::cout << "DOUBLE" << std::endl;
	
	if (data < 32 || data > 126)
		std::cout << "char: " << "Non displayable." << "\n";
	else
		std::cout << "char: " << "'" << static_cast<char>(data) << "'"<< "\n";
	std::cout << "int: " << static_cast<int>(data) << "\n";
	std::cout << "float: " << static_cast<float>(data) << "f\n";
	std::cout << "double: " << data << "\n";
}

void ScalarConverter::find_type(std::string type)
{
	bool has_dot = false;

	if (type.length() == 1 && (type[0] < '0' || type[0] > '9'))
	{
		print_char_type(static_cast<char>(type[0]));
		return;
	}

	if (char_to_int_overflow(type.c_str()))
	{
		std::cout << "ERROR - Overflow detected type conversion impossible.\n";
		return;
	}	

	for(unsigned long i = 0; i < type.length(); i++)
	{
		if (type[i] >= '0' && type[i] <= '9')
			continue;
		
		if (type[i] == '-' && i == 0)
			continue;
			
		if (type[i] == '.' && has_dot == false)
		{
			has_dot = true;
			continue;
		}
		
		if (type[i] == 'f' && type.length() == i + 1)
		{
			print_float_type(atof(type.c_str()));
			return;
		}
		std::cout << "ERROR - Type conversion impossible: " << type[i] << "\n"; 
		return;
	}
	if (has_dot == false)
		print_int_type(atoi(type.c_str()));
	else
		print_double_type(atof(type.c_str()));
}

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


