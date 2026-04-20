/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:28:18 by nsaillez          #+#    #+#             */
/*   Updated: 2026/04/20 11:28:06 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(const std::string& input)
{
	std::cout << "constructor called" << std::endl;
	this->expr = input;
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

void RPN::calculate()
{
	char token_type[] = {'+', '-', '*', '/'};
	std::stack<int> temp;
	
	for (size_t i = 0; i < expr.size(); i++)
	{
		std::cout << "'" << expr[i] << "'" << " ";
		for (size_t j = 0; j < sizeof(token_type) / sizeof(token_type[0]); j++)
		{
			if (expr[i] == token_type[j])
			{
				std::cout << "is a token" << std::endl;
				// look if there is at least 2 digit in the stack? if not error, if yes do operation remove from stack and push the result to stack.
				continue;
			}
		}
		if (isdigit(expr[i]))
		{
			std::cout << "is a digit" << std::endl;
			temp.push(static_cast<int>(expr[i] - '0'));
			continue;
		}
		std::cerr << "\033[31m" << "is neither a digit or a token, operation cancelled." << "\033[0m" << std::endl;
		break;
	}
	
}