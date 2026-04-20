/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:28:18 by nsaillez          #+#    #+#             */
/*   Updated: 2026/04/20 13:59:49 by nsaillez         ###   ########.fr       */
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
	int a;
	int b;
	char c;
	std::stack<int> temp;
	
	for (size_t i = 0; i < expr.size(); i++)
	{
		c = expr[i];
		//std::cout << "'" << expr[i] << "' ";
		if (i % 2)
		{
			if (c != ' ')
			{
				std::cerr << "\033[31m" << "Error: space missing between digit/operator" << "\033[0m" << std::endl; return;
				break;
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			std::cout << "is a token" << std::endl;
			if (temp.size() < 2)
			{
				std::cerr << "\033[31m" << "Error: not enough digit for the operation" << "\033[0m" << std::endl; return;
			}
			a = temp.top();
			temp.pop();
			b = temp.top();
			temp.pop();
			switch (c)
			{
			case '+':
				temp.push(a + b); break;
			case '-':
				temp.push(a - b); break;
			}
			std::cout << "RESULT: " << temp.top() << std::endl;
		}
		else if (isdigit(expr[i]))
		{
			std::cout << "is a digit" << std::endl;
			temp.push(expr[i] - '0');
		}
		else
		{
			std::cerr << "\033[31m" << "is neither a digit or a token, operation cancelled." << "\033[0m" << std::endl;
			break;	
		}
	}
}