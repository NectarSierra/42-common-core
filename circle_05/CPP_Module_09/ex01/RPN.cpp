/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 12:28:18 by nsaillez          #+#    #+#             */
/*   Updated: 2026/04/20 15:03:13 by nsaillez         ###   ########.fr       */
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
	long long a;
	long long b;
	char c;
	std::stack<long long> temp;
	
	for (size_t i = 0; i < expr.size(); i++)
	{
		c = expr[i];
		//std::cout << "'" << expr[i] << "' ";
		if (i % 2)
		{
			if (c != ' ')
			{
				std::cerr << "\033[31m" << "Error: space missing at col.: " << i << "\033[0m" << std::endl; return;
				break;
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			// std::cout << "is a token" << std::endl;
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
				temp.push(b + a); break;
			case '-':
				temp.push(b - a); break;
			case '*':
				temp.push(b * a); break;
			case '/':
				if (a == 0)
				{
					std::cerr << "\033[31m" << "Error: Cannot divide by 0" << "\033[0m" << std::endl;
					return;
				}
				temp.push(b / a); break;
			}
		}
		else if (isdigit(expr[i]))
		{
			// std::cout << "is a digit" << std::endl;
			temp.push(expr[i] - '0');
		}
		else
		{
			std::cerr << "\033[31m" << "Error: '" << c << "' is neither a digit or a token, operation cancelled." << "\033[0m" << std::endl;
			return;
		}
	}
	if ((expr.size() + 1) % 2)
		std::cerr << "\033[31m" << "Error: RPN has to be finished by either a digit or an operator" << "\033[0m" << std::endl;
	else if (temp.size() - 1 != 0)
		std::cerr << "\033[31m" << "Error: digit are missing operator" << "\033[0m" << std::endl;
	else
		std::cout << "Result: " << temp.top() << std::endl;
}