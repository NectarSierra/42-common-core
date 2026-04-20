/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:28:18 by nsaillez          #+#    #+#             */
/*   Updated: 2026/04/20 09:09:07 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& input)
{
	std::cout << "constructor called" << std::endl;
	std::cout << input << std::endl;
}

RPN::RPN(const RPN& other)
{
	std::cout << "copy constructor called" << std::endl;
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// ..
	}
	return *this;
}

RPN::~RPN()
{
	std::cout << "destructor called" << std::endl;
}