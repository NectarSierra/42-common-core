/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 08:49:20 by nsaillez          #+#    #+#             */
/*   Updated: 2026/01/05 13:18:25 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iomanip>
#include <cstdlib>

int	overflow_check(int res, int digit, int isneg)
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

int	char_to_int_overflow(const char *str)
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
	if (str[i] == '.')
			return (0);
	if (str[i] || str[i - 1] == '-' || str[i - 1] == '+')
		return (-1);
	return (0);
}

void is_int(std::string type)
{
	// std::cout << "int\n";
	int v = std::atoi(type.c_str());
	std::cout << std::setprecision(1) << std::fixed;


	if (v < 33 || v > 126)
		std::cout << "char: " << "Not displayable" << "\n";
	else
		std::cout << "char: " << "'" << static_cast<char>(v) << "'"<< "\n";
	std::cout << "int: " << v << "\n";
	std::cout << "float: " << static_cast<float>(v) << "f\n";
	std::cout << "double: " << static_cast<double>(v) << "\n";
	return ;
}

void is_float(std::string type)
{
	// std::cout << "float\n";
	float v = std::atof(type.c_str());
	std::cout << std::setprecision(1) << std::fixed;


	if (v < 33 || v > 126)
		std::cout << "char: " << "Not displayable" << "\n";
	else
		std::cout << "char: " << "'" << static_cast<char>(v) << "'"<< "\n";
	std::cout << "int: " << static_cast<int>(v) << "\n";
	std::cout << "float: " << v << "f\n";
	std::cout << "double: " << static_cast<double>(v) << "\n";
	return ;
}

void is_double(std::string type)
{
	// std::cout << "double\n";
	double v = std::atof(type.c_str());
	std::cout << std::setprecision(1) << std::fixed;


	if (v < 33 || v > 126)
		std::cout << "char: " << "Non displayable" << "\n";
	else
		std::cout << "char: " << "'" << static_cast<char>(v) << "'"<< "\n";
	std::cout << "int: " << static_cast<int>(v) << "\n";
	std::cout << "float: " << static_cast<float>(v) << "f\n";
	std::cout << "double: " << v << "\n";
	return ;
}

void find_type(std::string type)
{
	bool dot = false;
	bool f = false;
	
	if (!type.compare("+inff") || !type.compare("-inff"))
		return is_float(type);
	if (!type.compare("+inf") || !type.compare("-inf"))
		return is_double(type);
		
	for(int i = 0; i < static_cast<int>(type.length()); i++)
	{
		if (type[i] == '-' && i == 0)
		{
			continue;
		}
			
		if (type[i] < '0' || type[i] > '9')
		{
			if (type[i] == '.')
			{
				if (dot == true)
				{
					std::cout << "char: " << "Impossible" << "\n";
					std::cout << "int: " << "Impossible" << "\n";
					std::cout << "float: " << "nan" << "f\n";
					std::cout << "double: " << "nan" << "\n";
					return;
				}
				dot = true;
				continue;
			}
			if (static_cast<int>(type.length()) == i + 1)
			{
				f = true;
				break;
			}
			std::cout << "char: " << "Impossible" << "\n";
			std::cout << "int: " << "Impossible" << "\n";
			std::cout << "float: " << "nan" << "f\n";
			std::cout << "double: " << "nan" << "\n";
			return;
		}
	}

	if (dot == false)
		is_int(type);
	else if (f == false)
		is_double(type);
	else
		is_float(type);
}

void ScalarConverter::convert(std::string type)
{
	if (type.length() == 1)
	{
		char a = static_cast<char>(type[0]-'0');
		if (a < 32 || a > 126)
			std::cout << "char: " << "Not displayable" << "\n";
		else
			std::cout << "char: " << a << "\n";
		std::cout << "int: " << static_cast<int>(a) << "\n";
		std::cout << "float: " << static_cast<float>(a) << ".0f\n";
		std::cout << "double: " << static_cast<double>(a) << ".0\n";
	}
	else
	{
		if (char_to_int_overflow(type.c_str()))
		{
			std::cout << "Type conversion impossible.\n";
			return;
		}
		find_type(type);
	}
}


